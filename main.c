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

int main()
{
    init_sdl();
    SDL_Surface *img = load_image("img/McCord2.jpg");
    convert_to_grey(img);
    int *matrix = malloc(img->h*img->w*sizeof(int));
    img_integrale(img, matrix);
    haarFeatures(matrix, img->w, img->h);
    FILE *f = fopen("ADATEST", "a");

    Sample  sample[1];
    char file[] = "/home/zionlion/project/WhoIsWho/HAARCARACS";
    sample[0].filename = file;
    sample[0].positive = 1;

    StrongClassifier strong = adaBoost(sample,1,0,1,162336);
    for(int i = 0; i < strong.count; i++)
    {
        fprintf(f," WEAK CLASSIFIER %d :\nINDEX : %d\nERROR :%f\nTHRESHOLD : %d\n ALPHA : %f\n\n ",i,
                strong.wc[i].index,strong.wc[i].error,
                strong.wc[i].treshold,
                strong.wc[i].alpha);
    }

    int boole = applyStrongClassifier(strong,sample[0]);
    printf("%d\n",boole);

    fclose(f);

    return 0;
    
    
}

