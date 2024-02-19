# ixana_device

Instructions: 
In the main.cpp file, inside the main function 3 functions for each mode have been called. Please uncomment the one you need to run.

points to note:

1. CTRL pin direction is being changed on the fly for mode 1. Not sure if the same should be done for NRST pin in mode 2.
2. Open drain setting have been provided only for MCU output pin in gpio.hpp but it is needed for input pin e.g DONE pin. 
3. send_communications function has not been called in mode 1 as the comms signal has not been shown there. For similar reasons timeout for Done signal has not been added in mode 1 and mode 2.
4. pin init, deinit and write function failure is not handled as it is not clear what would be the failure handling for it.

time estimate ~2hrs and 15 mins