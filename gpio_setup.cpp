#include "./inc/board.h"
#include "./inc/coms.h"
#include "./inc/delay.h"
#include "./inc/gpio.hpp"
#include "gpio_setup.hpp"

/*structs for corresponding to each pin*/
gpio_out_t GPIO_NRST = {PIN_NRST};
gpio_out_t GPIO_NTEST = {PIN_NTEST};
gpio_out_t GPIO_CTRL = {PIN_CTRL};
gpio_out_t GPIO_SELECT = {PIN_SELECT};

gpio_in_t GPIO_DONE = {PIN_DONE};
gpio_in_t GPIO_SUCCESS = {PIN_SUCCESS};
gpio_in_t GPIO_CTRL_IN = {PIN_CTRL};


void gpio_input_init(gpio_in_t& g_pin, PUPD pp)
{  
   g_pin.init(pp);
}

void gpio_output_init(gpio_out_t& g_pin, PUPD pp, OUT out_type)
{
    g_pin.init(pp, out_type);
}

void pin_setup()
{
    //configure output pins
    gpio_output_init(GPIO_NRST, PUPD_UP, OUT_PUSHPULL);
    gpio_output_init(GPIO_NTEST, PUPD_UP, OUT_PUSHPULL);
    gpio_output_init(GPIO_CTRL, PUPD_UP, OUT_PUSHPULL);
    gpio_output_init(GPIO_SELECT, PUPD_UP, OUT_PUSHPULL);

    //configure input pins
    gpio_input_init(GPIO_DONE, PUPD_UP);
    gpio_input_init(GPIO_SUCCESS, PUPD_UP);
}

void board_device_init()
{
    pin_setup();
    GPIO_NTEST.write(high);
    GPIO_SELECT.write(low);
}

