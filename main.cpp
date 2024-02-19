
#include "gpio_setup.hpp"
#include "modes.hpp"
#include <iostream>


int main()
{
   board_device_init();

   /*Uncomment function for entering corresponding mode*/

   enter_mode_0();

   enter_mode_1();

   enter_mode_2();

   std::cout<<"no issues"<<std::endl;

}