## Simple SDL mini code
 
CC=gcc
 
CPPFLAGS= `pkg-config --cflags sdl glib-2.0`
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl glib-2.0` -lSDL_image
 
SRC= ../SDLIMAGE/pixel_operations.c ../SDLIMAGE/basic_fun.c base.c
OBJ= ${SRC:.c=.o}
 
all: base
 
base: ${OBJ}

clean:
	rm -f *~ *.o
	rm -f base

# END
