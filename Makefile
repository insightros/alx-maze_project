
CC = gcc

SRC = src/*.c

NAME = maze

RM = rm -f

CFLAGS = -O2 -g -Wall -Werror -Wextra -pedantic -Isrc/headers

LFLAGS = -lSDL2 -lSDL2_image -lm

SDLFLAGS = `sdl2-config --cflags --libs`


all: $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(SDLFLAGS)

clean:
	$(RM) *~ $(NAME)
