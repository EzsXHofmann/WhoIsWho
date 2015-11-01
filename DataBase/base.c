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
    char *path = "img/";
    GError **error = malloc(sizeof(GError**));
    GDir* dir = g_dir_open(path, 0, error);
    G_CONST_RETURN gchar* file = g_dir_read_name(dir);

    while (file != NULL)
    {
        path = "img/";
        strcpy(temp->name, file);
        temp->img = load_image(strcat(path, file));
        temp->next = malloc(sizeof(EltDB*));
        //temp->cls = recuperation StrongClassifier de l'image
        temp = temp->next;
        file = g_dir_read_name(dir);
    }
    
    g_dir_close(dir);
    free(error);
}

int ajout_eltDB(EltDB *begin, gchar *name)
{
    EltDB *temp = begin;
    EltDB *new = malloc(sizeof(EltDB*));
    while(temp != NULL && *(temp->name) != *name)
    {
        if(*(temp->name) > *name)
        {
            strcpy(new->name, name);
            new->next = temp->next;
            temp->next = new;
            return 1;
        }
        temp = temp->next;
        
    }
    if (temp == NULL)
    {
        temp = malloc(sizeof(EltDB*));
        strpy(temp->name, name);
        temp->next = NULL;
        return 1;
    }
    return 0;
}

int main()
{
    init_sdl();
    EltDB *begin = malloc(sizeof(EltDB*));
    initializeDB(begin);
    display_image(begin->img);
}
