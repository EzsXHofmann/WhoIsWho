#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


void haarFeature1(SDL_Surface *detec, int ii[])
{ 
    //detec = fenetre de detection
    //ouvre le fichier mode écriture pointeur à la fin du fichier
    FILE *file = fopen("HAARCARACS","a");
    if(file == NULL)
        printf("ERROR OPENING FILE\n");
    int i = 0, j = 0;
    int h = 1, w = 1; //h inutile c'est des carres donc h = w
    int s1 = 0, s2 = 0;
    int res = 0;
    while(i + h < detec->h && j + w < detec->w) //boucle pour scale
    {
    for(i = 0; i < detec->h && i + h < detec->h; i++)
    {   int  offset = i*detec->w;
        for(j = 0; j < detec->w && j + w < detec->w;j++)
        {   //save la position[i,j] au debut du parcours du feature
            int index = i, index2 = j;
            //parcours du feature (1 seul carré)
           for(int k = 0; k < h; k++)   
           {   int offset2 = (index+1)*detec->w; //ligne du dessous
               for(int l = 0; l < w; l++)
               {
                 //on utilise ls positions "virtuelles" [i,j] pour:
                 //avoir la pos du pixel courant selon i et j qui sont
                 //les valeurs correspondantes dans la matrix de pixel
                 //et accéder à l'image intégrale qui correspond à la
                 //matrice 
                    s1 += ii[offset + index2] + ii[offset2+index2+1]
                        - ii[offset+index2+1] - ii[offset2+index2];

                    s2 += ii[offset+index2+w] + ii[offset2+index2+w+1]
                        - ii[offset+index2+w+1]-ii[offset2+index2+w];
                    index2++;
               }
               
               index++;
           }
           res = s1 - s2; //différence blanc - noir
           int x = fprintf(file,"(1,%d,%d,%d,%d) = %d\n",i,j,w,h,res);
           if(x == 0) //erreur d'ecriture
               printf("Error writing in HAARCARACS");

        }
    }
    h *= 5/4; //scale du feature 
    w *= 5/4;
    }
  int  x = fclose(file);
    if(x != 0)
        printf("Error closing the file");
}

int main()
{ return 0;
}
