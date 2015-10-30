#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDLIMAGE/pixel_operations.h"
#include "SDLIMAGE/basic_fun.h"
#include "SDLIMAGE/sat.h"
#include "HAAR/features.h"

int main()
{
    init_sdl();
    SDL_Surface *img = load_image("/home/zionlion/Images/hs10.png");

    for (int i = 0; i < img->h; i++)
        for (int j = 0; j < img->w; j++)
            putpixel(img, j, i, 1);

    int *matrix = malloc(img->h*img->w*sizeof(int));
    img_integrale(img, matrix);
    for(int i = 0; i < 24; i++)
    {  int offset = i * img->w;
       for(int j = 0; j < 24; j++)
       {
           printf("%3d ", matrix[offset + j]);

       }
       printf("\n");
    } 
    haarFeatures(matrix, img->w, img->h);

    SDL_FreeSurface(img);
    free(matrix);
    return 0;
}
