all : unittest_climber 

check : $(TARGET)
	./$^

CC=gcc
CXX=g++
CFLAGS= -g -D_DEBUG -fPIC -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wsign-compare -Winvalid-pch -fms-extensions -Wall -MMD
CPPFLAGS=$(CFLAGS) -Woverloaded-virtual -Wsign-promo -fno-gnu-keywords -std=c++11 -pg

OBJ =  main.o  

unittest_climber: main.o 
	$(CXX) $(CPPFLAGS)  -o $@ $(OBJ)

main.o: main.cc 
	$(CXX) $(CPPFLAGS) -c main.cc


clean:
	-rm *.o *.d unittest_climber 
