SOURCES=screen.c game.c pieces.c score.c
HEADERS=screen.h game.h pieces.h score.h
CFLAGS=-O2 -Wall -Wextra -pedantic -Wno-vla -std=c99 
LDFLAGS=-lncurses -lm
BINNAME=tetris

$(BINNAME): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ $(LDFLAGS)
