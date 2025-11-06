DIR := build
TARGET := $(DIR)/hello
FILE := hello.c
SRC_DIR := SRC
CC := gcc
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(DIR)/%.o, $(SRC))

all: $(TARGET)	

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(DIR)/%.o: $(SRC_DIR)/%.c $(DIR)
	$(CC) -c $< -o $@

clean:
	rm -rf $(DIR)

$(DIR):
	mkdir -p $@
