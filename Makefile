DEBUG ?= 0

export INST_PREFIX   ?= /usr/local/facematica/facepycessor
ALT_INCLUDE      = ../faceSDK/VOCORDsdk/include/
LOCAL_INCLUDE = /usr/local/include
W_FLAGS	     = -Wall -Wno-unused -Wno-deprecated
CFLAGS       += $(W_FLAGS) -std=c++11
LIB_PATH = -L/usr/local/lib -L../faceSDK/lib
LIBS = 
#LIBS = -lfacesdk
#LIBS = ../faceSDK/VOCORDsdk/Release/libVOCORDsdk.a
#LIBS += -lboost_python -lgflags -lglog -lcaffe -lboost_system -lboost_filesystem -lprotobuf -lopencv_core -lopencv_highgui -lopencv_objdetect -lopencv_imgproc -lopencv_imgcodecs -lopencv_cudawarping -lmxnet -lpthread 

OBJS = facemachine.o matchmachine.o sexmachine.o json11.o
CWD = $(shell pwd)
#PYTHON_INCLUDES = $(shell python-config --includes)
PYTHON_INCLUDES =
TARGET=libfacematica_wrap.so

ifeq "$(findstring Linux, $(shell uname -o))" "Linux"
	CFLAGS += -fPIC -pthread
endif

ifeq "$(DEBUG)" "0"
	CFLAGS += -O2
else
	CFLAGS += -O0 -g -gdwarf-2
endif

all: $(TARGET)
	make -C test

$(TARGET): $(OBJS)
	$(CXX) -shared ./*.o -o $@ $(LIB_PATH) $(LIBS)
	ln -f $(CWD)/$(TARGET) ./test/$(TARGET)
ifeq "$(DEBUG)" "0"
	strip $@
endif

%.o:%.cpp
	$(CXX) $(CFLAGS) -I$(ALT_INCLUDE) -I$(LOCAL_INCLUDE) $(PYTHON_INCLUDES) $< -c -o $@

json11.o:json11/json11.cpp
	$(CXX) $(CFLAGS) -I$(INCLUDE) -I$(ALT_INCLUDE) -I$(LOCAL_INCLUDE) $< -c -o $@

clean:
	@rm -f ./*.o ./*.so
	@rm -f ./test/*.so
	make clean -C test
	@rm -f ./tmp/*.*

.PHONY: test
test:
	./test/tstconsole.sh

install:
	install -pD $(TARGET) $(INST_PREFIX)/$(TARGET)
