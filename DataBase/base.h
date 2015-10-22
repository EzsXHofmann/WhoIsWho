#ifndef BASE_H_
#define BASE_H_

#include <stdlib.h>
#include <SDL.h>
#include <SDL/SDL_image.h>

typedef struct EltDB EltDB;
struct EltDB
{
    SDL_Surface *img;
    char *name;
    struct EltDB *next;
};

void initializeDB(EltDB *begin);

#endif
