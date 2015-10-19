#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

//DW = fenêtre de détection
//ii = image intégrale

void changeparameters(int *h, int *w, int *inc1, int *inc2, int type)
{
    if (type == 1)
        *h = 0, *w = 1, *inc1 = 2, *inc2 = 1;
    if (type == 2)
        *h = 0, *w = 2, *inc1 = 3, *inc2 = 1;
    if (type == 3)
        *h = 1, *w = 0, *inc1 = 1, *inc2 = 2;
    if (type == 4)
        *h = 2, *w = 0, *inc1 = 1, *inc2 = 3;
    if (type == 5)
        *h = 1, *w = 1, *inc1 = 2, *inc2 = 2;
}

void haarFeatures(int ii[], int width, int height)
{
    FILE *file = fopen("HAARCARACS", "a");
    if (file == NULL)
        printf("ERROR OPENING FILE\n");

    int c = 24, ori, res, err, w2, h2, inc1, inc2;

    //La taille de la DW doit être <= à la taille de l'ii
    while (c <= width && c <= height)
    {
        //Toutes les positions possibles de la DW
        for (int j = 0; j + c < height; j++)
        {
            for (int i = 0; i + c < width; i++)
            {
                for (int type = 1; type < 6; type++)
                {
                    changeparameters(&h2, &w2, &inc1, &inc2, type);

                    fprintf(file, "(%d, %d, %d, %d) :\n", type, i, j, c);
                    //Différentes tailles du feature
                    for (int h = h2; h < c; h += inc2)
                    {
                        for (int w = w2; w < c; w += inc1)
                        {
                            //Positions du feature
                            for (int y = 0; y + h <= c; y++)
                            {
                                for (int x = 0; x + w <= x; x++)
                                {
                                    ori = j*width + i + width * y + x;

                                    res = calcul(ii, type, w, h, width, x, y, ori);

                                    err = fprintf(file, "%d\n", res);
                                    if (err == 0)
                                        printf("Error writing in HAARCARACS");
                                }
                            }
                        }
                    }
                }
            }
        }

        c = c*5/4;
    }
}

int main()
{
    return 0;
}
