CXX ?= g++
INCLUDE = -I..
CFLAGS += -pipe -std=c++11 $(INCLUDE) -Wall -pthread -ggdb -gdwarf-2
LIBS =  -L.. -L. -lfacematica_wrap
LFLAGS =  -pthread
TARGET = tstconsole

all: tstconsole

tstconsole:./tstconsole.cpp
	$(CXX) $(CFLAGS) $(LFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f $(TARGET)
	@rm -f ./*.o

