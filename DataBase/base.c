#include <stdlib.h>
#include <stdio.h>
#include <glib.h>
#include <glib/gdir.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDLIMAGE/basic_fun.h"
#include "../SDLIMAGE/pixel_operations.h"
#include "base.h"

void initializeDB(EltDB *begin)
{
    EltDB *temp = begin;
    char *path = "../img/";
    GError **error = malloc(sizeof(GError**));
    GDir* folder = g_dir_open(path, 0, error);
    G_CONST_RETURN gchar* file = g_dir_read_name(folder);

    while (file != NULL)
    {
        path = "../img/";
        strcpy(temp->name, file);
        temp->img = load_image(strcat(path, file));
        temp->next = malloc(sizeof(EltDB*));
        temp = temp->next;
    }
    
    g_dir_close(folder);
    free(error);
}

int main()
{
    init_sdl();
    EltDB *begin = malloc(sizeof(EltDB*));
    initializeDB(begin);
    display_image(begin->img);
}
