BUILD_DIR = _build

CC = g++
CC_FLAGS = 
CC_LDFLAGS = -lm

all: clean build
	$(CC) -o $(BUILD_DIR)/test_quant tests/test_quant.cc $(CC_LDFLAGS)
	$(BUILD_DIR)/test_quant

build:
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
