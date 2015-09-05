# weizili@360.cn 

CC=gcc
CXX=g++
CFLAGS= -g -D_DEBUG -fPIC -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wsign-compare -Winvalid-pch -fms-extensions -Wall -MMD
CPPFLAGS=$(CFLAGS) -Woverloaded-virtual -Wsign-promo -fno-gnu-keywords -std=c++11


OBJS := main.o ini_parser.o  


TARGET=unittest_iniparser

all : $(TARGET) 

check : $(TARGET)
	./$^

$(TARGET) : $(OBJS)
	$(CXX) $(CPPFLAGS) -o $@ $(OBJS)



ini_parser.o: ini_parser.cc ini_parser.h
	$(CXX) $(CPPFLAGS) -c ini_parser.cc

main.o: main.cc ini_parser.h
	$(CXX) $(CPPFLAGS) -c main.cc

clean:
	rm -rf *.o *.d $(OBJS) $(DEPS) $(TARGET) 

