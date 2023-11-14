CC = gcc
CFLAGS = -Wall -g
SRC_DIR = ../src
BIN_DIR = ../bin
ADT_DIR = $(SRC_DIR)/ADT

all: $(BIN_DIR)/main
	
$(BIN_DIR)/main: $(ADT_DIR)/kata.c $(ADT_DIR)/detaillagu.c $(ADT_DIR)/mesinkarakter.c $(ADT_DIR)/mesininput.c $(ADT_DIR)/mesinfile.c $(ADT_DIR)/listdinamik.c $(ADT_DIR)/liststatik.c $(ADT_DIR)/map.c $(ADT_DIR)/queue.c $(ADT_DIR)/set.c $(ADT_DIR)/stack.c $(ADT_DIR)/strukturberkait.c $(SRC_DIR)/data.c $(SRC_DIR)/console.c $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BIN_DIR)/main
	rm -rf $(BIN_DIR)/main.dSYM
	clear