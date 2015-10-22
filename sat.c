# include <stdlib.h>
# include <stdio.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include "../SDLIMAGE/pixel_operations.h"
# include "../SDLIMAGE/basic_fun.h"

void img_integrale(SDL_Surface *img,int *sat)
{
   
    for(int i = 0; i < img->w; i++)
    {   int offset = i*(img->h);
        for(int j = 0; j < img->h; j++)
        {
          Uint32  pixel = getpixel(img,i,j);
          int *pixel2 = 0;
          if(i > 0)
          {
              *pixel2 = sat[offset - 1 + j];
              *pixel2 += pixel;
          }
          if(j > 0)
          {
              *pixel2 = sat[offset + j - 1]; 
              *pixel2 += pixel;
          }
          if(i > 0 && j > 0)
          {
              *pixel2 = sat[offset - 1 + j - 1];
               pixel -= *pixel2;
              *pixel2 = (int)pixel;
               
          }
         sat[offset + j] = *pixel2;
          
        }
    }
    
}

}
int main()
{
 //   init_sdl();
//	SDL_Surface *img = load_image("/home/zionlion/Images/test.jpg"); 
  //  SDL_Surface *sat = image_int(img);
    //img = display_image(sat);
 //   SDL_FreeSurface(img);       
  //  SDL_FreeSurface(sat);
    return 0;
}
