DIR := build
TARGET := hello
FILE := hello.c
SRC := SRC
CC := gcc

all: $(DIR) $(TARGET)

$(TARGET): hello.o $(DIR)
	$(CC) $(DIR)/hello.o -o $(DIR)/$(TARGET)

hello.o: $(DIR)
	$(CC) -c $(SRC)/$(FILE) -o $(DIR)/hello.o

clean:
	rm -rf build

$(DIR):
	mkdir $(DIR)
