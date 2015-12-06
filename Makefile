# simple SDL mini code
 
CC=gcc
 
CPPFLAGS= `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -Werror -std=c99 -pedantic -g -fvar-tracking -O3 
LDFLAGS= -lm
LDLIBS= `pkg-config --libs sdl` -lSDL_image 
 
SRC= SDLIMAGE/pixel_operations.c SDLIMAGE/basic_fun.c SDLIMAGE/sat.c HAAR/compute.c HAAR/features.c  Adaboost/adaboost.c CASCADE/cascade.c main.c  
OBJ= ${SRC:.c=.o}
 
all: main 
 
main: ${OBJ}
 
clean:
	rm -f *~ *.o
	rm -f main
	rm -f Adaboost/*.o Adaboost/*~
	rm -f CASCADE/*.o CASCADE/*~
	rm -f DataBase/*.o DataBase/*~
	rm -f EIGEN/*.o EIGEN/*~
	rm -f HAAR/*.o HAAR/*~
	rm -f HAARCARACS
	rm -f SDLIMAGE/*.o SDLIMAGE/*~
	rm -f ADATEST
	rm -f TEST
	rm -f cascade
# END
