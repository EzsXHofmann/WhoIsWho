#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDLIMAGE/pixel_operations.h"
#include "SDLIMAGE/basic_fun.h"
#include "SDLIMAGE/sat.h"
#include "HAAR/features.h"
#include "Adaboost/adaboost.h"
#include <string.h>
#include "CASCADE/cascade.h"

int main()
{
    Sample samples[125];
    int  i;
    for( i = 0; i < 9; i++)
    {
        char *path = malloc(100*sizeof(char));  
        sprintf(path, "img/faces/subject0%d.gif",i+1);
        samples[i].filename = path;
        free(path);
    }

    for(i = 9; i < 15; i++)
    {
        char *path = malloc(100*sizeof(char));  
        sprintf(path, "img/faces/subject%d.gif",i+1);
        samples[i].filename = path;
        free(path);
    }

    for(i = 0; i < 9; i++)
    {
        char *path = malloc(100*sizeof(char));  
        sprintf(path, "img/faces/subject0%d.happy.gif",i+1);
        samples[i].filename = path;
        free(path);     
    }
    
}
