CXX=g++
RM=rm -f
CFLAGS=-c -w -Wall -std=c++11

testCoin: main.o functions.o 
	$(CXX) -g main.o functions.o -o testCoin

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

functions.o: functions.cpp functions.hpp
	$(CXX) $(CFLAGS) functions.cpp

clean:
	$(RM) testCoin *.o *~


