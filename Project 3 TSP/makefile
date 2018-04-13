CXX=g++
RM=rm -f
CFLAGS=-c -w -Wall -std=c++11

test: main.o functions.o 
	$(CXX) -g main.o functions.o -o test

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

functions.o: functions.cpp functions.hpp
	$(CXX) $(CFLAGS) functions.cpp

clean:
	$(RM) test *.o *~