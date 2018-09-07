CXX = g++
AR  = ar
LD  = ld

TOP_DIR = $(shell pwd)
INCLUDES = -I$(TOP_DIR)/../../output/include
LIBS = -L$(TOP_DIR)/../../output/lib

TARGET = add 

CXXFLAGS += -g -O2 -std=c++11 -Werror

all: $(TARGET)
	@echo "build $(TARGET) successful"

$(TARGET): add.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@ $< -lgraphflow

clean:
	rm -f $(TOP_DIR)/$(TARGET)

