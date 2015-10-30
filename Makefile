# simple SDL mini code
 
CC=gcc
 
CPPFLAGS= `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -Werror -std=c99 -O3 
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image
 
SRC= SDLIMAGE/pixel_operations.c SDLIMAGE/basic_fun.c SDLIMAGE/sat.c HAAR/calculs.c HAAR/features.c main.c
OBJ= ${SRC:.c=.o}
 
all: main
 
main: ${OBJ}
 
clean:
	rm -f *~ *.o
	rm -f main
	rm -f HAAR/*.o
	rm -f SDLIMAGE/*.o
	rm -f HAARCARACS
# END
