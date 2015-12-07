#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDLIMAGE/pixel_operations.h"
#include "SDLIMAGE/basic_fun.h"
#include "SDLIMAGE/sat.h"
#include "HAAR/features.h"
#include <string.h>

int main(int argc, char* argv[])
{   
    
    if (argc != 3 || strlen(argv[2]) != 1
                  || argv[2][0] < 48 || argv[2][0] > 49)
    {
        printf("Usage:\n%s <path> <mode>\nMode:", argv[0]);
        printf("\n\t0: Set all the pixels of the image to 1");
        printf("\n\t1: Do nothing else\n");
        printf("\n\t2: GUI\n");
        return 0;
    }

    int n = strtoul(argv[2], NULL, 10);

    init_sdl();
    SDL_Surface *img = load_image(argv[1]);
    
    if (n == 0)
    {
        for (int j = 0; j < img->h; j++)
            for (int i = 0; i < img->w; i++)
                putpixel(img, i, j, 0x10101);
    }

    if (n == 2)
    {
        EltDB *begin = Initialize();
        //VARIABLE
        gtk_init(&argc, &argv);
        GtkWidget* MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        GtkWindow* fenetre = GTK_WINDOW(MainWindow);
     
        //SETUP WINDOW
         
        initialize_window(fenetre);
        
        //EVENT
        g_signal_connect(G_OBJECT(MainWindow), "delete-event",
                         G_CALLBACK(gtk_main_quit), NULL);
         
        button_ajout(MainWindow, begin);

        return EXIT_SUCCESS;
    }

    int *matrix = malloc(img->h*img->w*sizeof(int));
    img_integrale(img, matrix);

    printf("\n-------------------- Integral Image --------------------\n");

    for (int i = 0; i < img->h; i++)
    {  
        int offset = i * img->w;
        
        for (int j = 0; j < img->w; j++)
            printf("%5d ", matrix[offset + j]);

        printf("\n");
    }
    
    printf("--------------------------------------------------------\n");
    
    haarFeatures(matrix, img->w, img->h);

    SDL_FreeSurface(img);
    free(matrix);
    return 0;
}
