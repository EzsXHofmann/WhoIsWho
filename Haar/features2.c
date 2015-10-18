#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

//DW = fenêtre de détection
//ii = image intégrale

void haarFeature1(int ii[], int width, int height)
{
    FILE *file = fopen("HAARCARACS", "a");
    if (file == NULL)
        printf("ERROR OPENING FILE\n");

    int s1, s2, c = 24;

    //La taille de la DW doit être <= à la taille de l'ii
    while (c <= width && c <= height)
    {
        //Toutes les positions possibles de la DW
        for (int j = 0; j + c < height; j++)
        {
            for (int i = 0; i + c < width; i++)
            {
                fprintf(file, "(1, %d, %d, %d) :\n", i, j, c);
                //Différentes tailles du feature
                for (int h = 0; h < c; h++)
                {
                    for (int w = 1; w < c; w += 2)
                    {
                        //Positions du feature
                        for (int y = 0; y + h <= c; y++)
                        {
                            for (int x = 0; x + w <= x; x++)
                            {
                                int ori = j*width + i + width * y + x;
                                if (x == 0 && y == 0)
                                {
                                    s1 = ii[ori + w + h*width];
                                    s2 = ii[ori + w/2 + h*width];
                                }
                                else
                                {
                                    if (x != 0 && y != 0)
                                    {
                                        s1 = ii[ori + w/2 + h*width]
                                           + ii[ori - 1 - width]
                                           - ii[ori + w/2 - width]
                                           - ii[ori - 1 + h*width];
                                        s2 = ii[ori + w + h*width]
                                           + ii[ori + w/2 - width]
                                           - ii[ori + w - width]
                                           - ii[ori + w/2 + h*width];
                                     }
                                     else
                                     {
                                         if (x == 0)
                                         {
                                             s1 = ii[ori + w/2 + h*width]
                                                - ii[ori + w/2 - width];
                                             s2 = ii[ori + w + h*width]
                                                + ii[ori + w/2 - width]
                                                - ii[ori + w - width]
                                                - ii[ori + w/2 + h*width];
                                         }
                                         else
                                         {
                                             s1 = ii[ori + w/2 + h*width]
                                                + ii[ori - 1 - width]
                                                - ii[ori + w/2 - width]
                                                - ii[ori - 1 + h*width];
                                             s2 = ii[ori + w + h*width]
                                                - ii[ori + w/2 + h*width];
                                     
                                         }
                                     }
                                }

                                int err = fprintf(file, "%d\n", s1 - s2);
                                if (err == 0)
                                    printf("Error writing in HAARCARACS");
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
