# include <stdlib.h>
# include <stdio.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include "pixel_operations.h"

void img_integrale(SDL_Surface *img,SDL_Surface *sat)
{
   
    for(int i = 0; i < img->w; i++)
    {
        for(int j = 0; j < img->h; j++)
        {
          Uint32  pixel = getpixel(img,i,j);
          Uint32 pixel2 = 0;
          if(i > 0)
          {
              pixel2 = getpixel(sat,i - 1, j);
              pixel += pixel2;
          }
          if(j > 0)
          {
              pixel2 = getpixel(sat,i,j - 1);
              pixel += pixel2;
          }
          if(i > 0 && j > 0)
          {
              pixel2 = getpixel(sat,i - 1, j - 1);
              pixel -= pixel2;
          }
          putpixel(sat,i,j,pixel);

           
        }
    }
    
}

int main()
{
    printf("NTM FDP\n");
    return 0;
}
