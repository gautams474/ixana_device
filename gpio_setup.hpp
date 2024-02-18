#ifndef GPIO_SETUP_HPP_
#define GPIO_SETUP_HPP_

#include "./inc/gpio.hpp"

//global variables for GPIO pin, to be used for writing/reading
extern gpio_out_t GPIO_NRST;
extern gpio_out_t GPIO_NTEST;
extern gpio_out_t GPIO_CTRL;
extern gpio_out_t GPIO_SELECT;

extern gpio_in_t GPIO_DONE;
extern gpio_in_t GPIO_SUCCESS;
extern gpio_in_t GPIO_CTRL_IN;

#define high true
#define low  false

void gpio_input_init(gpio_in_t& g_pin, PUPD pp);

void gpio_output_init(gpio_out_t& g_pin, PUPD pp, OUT out_type);

void board_device_init();

#endif 