ARCH ?= x86

ifeq ($(ARCH),x86)
		CC=g++
else
		CC=arm-linux-gnueabihf-gcc
endif

TARGET=test_cpp
#OBJS=main.o mp3.o
CPP:=\%.cpp
BUILD_DIR=build
SRC_DIR=.
INC_DIR=.
CFLAGS=$(patsubst %,-I%,$(INC_DIR))
INCLUDES=$(foreach dir,$(INC_DIR),$(wildcard $(patsubst)/*.h))

SOURCES=$(foreach dir,$(SRC_DIR),$(wildcard $(dir)/*.cpp))
OBJS=$(patsubst $(CPP),$(BUILD_DIR)/%.o,$(notdir $(SOURCES)))
VPATH=$(SRC_DIR)

$(BUILD_DIR)/$(TARGET):$(OBJS)
		$(CC) $^ -o $@

#main.o:
#	gcc -c main.c -o main.o

#mp3.o:
#	gcc -c mp3.c -o mp3.o

$(BUILD_DIR)/%.o:$(CPP) $(INCLUDES) | create_build
		$(CC) -c $< -o $@ $(CFLAGS)

.PHONY:clean create_build

clean:
	rm -r $(BUILD_DIR)

create_build:
	mkdir -p $(BUILD_DIR)
