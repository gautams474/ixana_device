
INC = -Iinc

HEADERS = gpio_setup.hpp modes.hpp inc/gpio.hpp inc/delay.h inc/board.h inc/coms.h

output: main.o modes.o gpio_setup.o gpio.o
	g++ main.o modes.o gpio_setup.o gpio.o -o output

main.o: main.cpp $(HEADERS)
	g++ $(INC) -c main.cpp 

modes.o: modes.cpp $(HEADERS)
	g++  $(INC) -c modes.cpp 

gpio_setup.o: gpio_setup.cpp $(HEADERS)
	g++  $(INC) -c gpio_setup.cpp

gpio.o: gpio.cpp $(HEADERS)
	g++ $(INC) -c gpio.cpp

clean: 
	rm *.o output

