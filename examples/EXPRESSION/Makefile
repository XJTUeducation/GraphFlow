CXX = g++
AR  = ar
LD  = ld

TOP_DIR = $(shell pwd)
INCLUDES = -I$(TOP_DIR)/../../output/include
LIBS = -L$(TOP_DIR)/../../output/lib

TARGET = expression

CXXFLAGS += -g -O2 -std=c++11 -Werror

all: $(TARGET)
	@echo "build $(TARGET) successful"

$(TARGET): expression.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@ $< -lgraphflow

clean:
	rm -f $(TOP_DIR)/$(TARGET)

