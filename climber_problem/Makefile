all : unittest_climber 

check : $(TARGET)
	./$^

CC=gcc
CXX=g++
CFLAGS= -g -D_DEBUG -fPIC -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wsign-compare -Winvalid-pch -fms-extensions -Wall -MMD
CPPFLAGS=$(CFLAGS) -Woverloaded-virtual -Wsign-promo -fno-gnu-keywords -std=c++11 -pg

OBJ =  main.o Mountain.o 

unittest_climber: main.o Mountain.o
	$(CXX) $(CPPFLAGS)  -o $@ $(OBJ)

main.o: main.cc Mountain.h
	$(CXX) $(CPPFLAGS) -c main.cc

Mountain.o: Mountain.cpp Mountain.h 
	$(CXX) $(CPPFLAGS) -c Mountain.cpp

clean:
	-rm *.o *.d unittest_climber 
