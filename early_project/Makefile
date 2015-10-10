# simple SDL mini code
 
CC=gcc
 
CPPFLAGS= `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3 
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image
 
SRC= pixel_operations.c sat.c
OBJ= ${SRC:.c=.o}
 
all: sat
 
sat: ${OBJ}
 
clean:
	rm -f *~ *.o
	rm -f main 
# END
