.default: all

all: class10_example

clean:
	rm -f class10_example *.o

class10_example: main.o CoordinateBlock.o
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^ -lmcpp

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^