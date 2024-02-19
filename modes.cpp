
#include "./inc/gpio.hpp"
#include "gpio_setup.hpp"
#include "./inc/board.h"
#include "./inc/coms.h"
#include "./inc/delay.h"

/* configuration data to be transferred to device*/
uint8_t data[5] = { 1,1,1,1,1};
uint32_t size = sizeof(data);
uint32_t max_delay_us = 2*(1 + size*8);

void enter_mode_0()
{
    uint32_t config_time = 0;
    uint32_t new_time = 0;
    bool done_timeout = false;
  
    GPIO_CTRL.write(low);
    GPIO_SELECT.write(high);

    //nrst negative pulse
    GPIO_NRST.write(low);
    vcca(true);
    delay_us(100);
    vccb(true);
    delay_us(20000);

    //nrst pos edge
    GPIO_NRST.write(high);
    delay_us(10000);

    /*send configuration data*/
    send_communications(data, size);
    
    config_time = time_us();

    /*poll for DONE pin status*/
    while(GPIO_DONE.read() != true)
    {
        /*timeout added in case DONE pin never goes high*/
        new_time = time_us();
        if(new_time < config_time)
        {
            /*counter overflow case*/
            if((UINT32_MAX - config_time) + new_time > max_delay_us)
            {
                done_timeout = true;
                break;
            }  
        }
        else
        {
            /*regular case*/
            if(new_time - config_time > max_delay_us)
            {
                done_timeout = true;
                break;
            }
        }
    };

    if(done_timeout == false && GPIO_SUCCESS.read() != true )
    {
        //failed to configure to mode 1, add error handling here*/
    }

    if(done_timeout == true)
    {
        //DONE pin never got set to high by device, add error handling */
    }

    /*power down*/
    vccb(low);
    vcca(low);

}


void enter_mode_1()
{
    GPIO_CTRL.write(low);
    GPIO_SELECT.write(high);
    
    //nrst negative pulse
    GPIO_NRST.write(low);
    vcca(true);
    /*delay below to allow vcca to stabilize*/
    delay_us(100);
    vccb(true);
    delay_us(15000);
    GPIO_CTRL.write(high);
    delay_us(5000);

    //nrst pos edge
    GPIO_NRST.write(high);

    /*5ms delay after nrst posedge according to data sheet*/
    delay_us(5000);
    /* change direction for cntrl pin to input*/
    GPIO_CTRL.deinit();
    gpio_input_init(GPIO_CTRL_IN, PUPD_NONE);
    
    /*poll for DONE pin true status*/
    /*NOTE timeout not added here as it is not clear if max delay formula would hold for mode1 without coms signal in diagram*/
    while(GPIO_DONE.read() != true);
   
    if(GPIO_SUCCESS.read() != true)
    {
        /*failed to configure to mode 1, handle error condition*/
    }

    /*power down*/
    vccb(low);
    vcca(low);
}

void enter_mode_2()
{
   
    /* change direction for cntrl pin to input*/
    gpio_input_init(GPIO_CTRL_IN, PUPD_NONE);

    /*change direction for reset pin too ? external control*/

    /*poll for DONE pin true status*/
    while(GPIO_DONE.read() != true);
        
   
    if(GPIO_SUCCESS.read() != true)
    {
        /*failed to configure to mode 2, handle error condition*/
    }

    /*power down*/
    vccb(low);
    vcca(low);

}
