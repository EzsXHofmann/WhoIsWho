# include <stdlib.h>
# include <stdio.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include "pixel_operations.h"
# include "basic_fun.h"

void img_integrale(SDL_Surface *img,int *sat)
{ 
    for(int i = 0; i < img->h; i++)
    {   
        int offset = i*(img->w);
        for(int j = 0; j < img->w; j++)
        {
          Uint32  pixel = getpixel(img,i,j);
          int pixel2 = pixel;

          if(i == 0 && j > 0)
              pixel2 += sat[j - 1];

          if(j == 0 && i > 0)
              pixel2 += sat[offset - img->w];

          if(i > 0 && j > 0)
             
               pixel2 += sat[offset + j - img->w] + sat[offset + j - 1]
                        - sat[offset + j - img->w - 1];

         sat[offset + j] = pixel2; 
        }
    }
    
} 
