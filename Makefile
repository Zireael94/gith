CC      ?= gcc
CFLAGS  ?= -std=c11 -Wall -Wextra -Werror -O2

SRC     := c_tutorial.c
ifeq ($(OS),Windows_NT)
BIN     := c_tutorial.exe
else
BIN     := c_tutorial
endif

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN) c_tutorial c_tutorial.exe

.PHONY: all run clean
