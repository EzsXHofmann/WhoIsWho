CC=gcc
 
CPPFLAGS= `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image
 
SRC= features2.c

OBJ= ${SRC:.c=.o}
 
all: features2
 
features: ${OBJ}
 
clean:
	rm -f *~ *.o
	rm -f features2 
 
