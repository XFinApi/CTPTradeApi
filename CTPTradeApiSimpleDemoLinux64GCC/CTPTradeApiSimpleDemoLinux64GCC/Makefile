CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -std=c++11 -I./TradeApi_linux64/Cpp/
LDFLAGS=-g
LDLIBS=./TradeApi_linux64/Cpp/XFinApi.ITradeApi.so

SRCS=main.cpp
OBJS=$(subst .cc,.o,$(SRCS))

all: $(OBJS)
	chmod +777 ./copy.sh
	./copy.sh
	$(CXX) $(CPPFLAGS) -o CTPTradeApiSimpleDemo $(OBJS) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJS)
