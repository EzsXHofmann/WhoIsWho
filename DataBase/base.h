#ifndef BASE_H_
#define BASE_H_

#include <stdlib.h>
#include <SDL.h>
#include <SDL/SDL_image.h>
#include "../Adaboost/adaboost.h"

typedef struct EltDB
{ 
    char *name;
    StrongClassifier cls;
    struct EltDB *next;
    struct EltDB *old;
    
} EltDB;

void initializeDB(EltDB *begin);

#endif
