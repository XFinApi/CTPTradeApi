CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11 -I./XTA_L64/Cpp/
LDFLAGS=-g
LDLIBS=./XTA_L64/Cpp/XFinApi.ITradeApi.so

SRCS=main.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: $(OBJS)
	chmod +777 ./copy.sh
	./copy.sh
	$(CXX) $(CPPFLAGS) -o CTPTradeApiSimpleDemoLinux64GCC $(OBJS) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJS)
