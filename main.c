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
    SDL_Surface *img2= load_image("img/tamere2.jpg");
    SDL_Surface *img3= load_image("img/bleu.jpg");
    convert_to_grey(img);
    convert_to_grey(img2);
    convert_to_grey(img3);
    int *matrix = malloc(img->h*img->w*sizeof(int));
    int *matrix2 = malloc(img2->h*img->w*sizeof(int));
    int *matrix3 = malloc(img3->h*img->w*sizeof(int));
    img_integrale(img, matrix);
    img_integrale(img2,matrix2);
    img_integrale(img3,matrix3);
    haarFeatures(matrix, img->w, img->h,"test1");
    haarFeatures(matrix2,img2->w,img2->h,"test2");
    haarFeatures(matrix3,img3->w,img3->h,"test3");
    FILE *f = fopen("ADATEST", "a");

    Sample  sample[3];
    char file[] = "/home/zionlion/project/WhoIsWho/test1";
    char file2[]= "/home/zionlion/project/WhoIsWho/test2";
    char file3[]= "/home/zionlion/project/WhoIsWho/test3";
    sample[0].filename = file;
    sample[0].positive = 1;
    sample[1].filename = file2;
    sample[1].positive = 1;
    sample[2].filename = file3;
    sample[2].positive = 0;

    StrongClassifier strong = adaBoost(sample,2,1,3,162336);
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
    free(matrix);
    free(matrix2);
    free(matrix3);

    return 0;
    
    
}

