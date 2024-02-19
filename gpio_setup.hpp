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

/// @brief wrapper function for input pin init in case board.h changes
/// @param pin struct
/// @param push pull pull configuration
void gpio_input_init(gpio_in_t& g_pin, PUPD pp);

/// @brief wrapper function for output pin init in case board.h changes
/// @param pin struct
/// @param push pull pull configuration
/// @param out_type for Pushpull or OD config
void gpio_output_init(gpio_out_t& g_pin, PUPD pp, OUT out_type);

/// @brief init function to be called once in the beginning
void board_device_init();

/// @brief deinit function to be called once at end
void board_device_deinit();

#endif 