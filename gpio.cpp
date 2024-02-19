#include "./inc/gpio.hpp"
#include "./inc/board.h"
#include "./inc/coms.h"
#include "./inc/delay.h"

/*empty declarations for library functions from /inc folder added for compilation*/
bool gpio_in_t::read()
{
    //
    return true;
};

bool gpio_in_t::init(PUPD pullup_pulldown)
{
    //
    return true;
};

bool gpio_in_t::deinit()
{
    //
    return true;
};

void gpio_out_t::write(bool value)
{

};

bool gpio_out_t::init(PUPD pullup_pulldown, OUT out_type)
{
    //
    return true;
};

bool gpio_out_t::deinit()
{
    //
    return true;
};

void delay_us(uint32_t us_)
{

};

uint32_t time_us()
{
  return 0;
};

void vcca(bool enable)
{

};

void vccb(bool enable)
{

};

bool send_communications(const void* data, uint32_t size)
{
    return true;
};