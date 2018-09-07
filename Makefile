CXX = g++
AR  = ar
LD  = ld

PLATFORM = LINUX
PLATFORM_OPT = __$(PLATFORM)__

TOP_DIR = $(shell pwd)
CORE_DIR = $(TOP_DIR)/core
INCLUDES = -I$(TOP_DIR) -I$(TOP_DIR)/core
OUTPUT_DIR = $(TOP_DIR)/output

TARGET = libgraphflow.so
SOURCES = $(wildcard *.cc $(CORE_DIR)/*.cc)

CXXFLAGS += -g -O2 -Wall -fPIC -shared -Wl,--no-as-needed -std=c++11 -D$(PLATFORM_OPT) -lpthread

all: $(TARGET) $(TOP_DIR)/examples
	@echo "build done!"

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@
	rm -rf $(OUTPUT_DIR)
	mkdir $(OUTPUT_DIR)
	mkdir $(OUTPUT_DIR)/include
	mkdir $(OUTPUT_DIR)/lib
	cp $(CORE_DIR)/*.h $(OUTPUT_DIR)/include
	cp $(TOP_DIR)/common/*.h $(OUTPUT_DIR)/include
	mv $(TOP_DIR)/$(TARGET) $(OUTPUT_DIR)/lib

$(TOP_DIR)/examples: $(TARGET)
	make -C $(TOP_DIR)/examples/ADDITION
	make -C $(TOP_DIR)/examples/EXPRESSION

clean:
	rm -rf $(OUTPUT_DIR)
	make -C $(TOP_DIR)/examples/ADDITION clean
	make -C $(TOP_DIR)/examples/EXPRESSION clean

