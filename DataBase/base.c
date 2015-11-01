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
    temp->old = NULL;
    char *path = "img/";
    GError **error = malloc(sizeof(GError**));
    GDir* dir = g_dir_open(path, 0, error);
    G_CONST_RETURN gchar* file = g_dir_read_name(dir);

    while (file != NULL)
    {
        path = "img/";
        strcpy(temp->name, file); 
        temp->next = malloc(sizeof(EltDB*));
        //temp->cls = recuperation StrongClassifier de l'image
        temp = temp->next;
        temp->old = temp;
        file = g_dir_read_name(dir);
    }
    
    g_dir_close(dir);
    free(error);
}

int ajout_eltDB(EltDB *begin, gchar *name)
{
    EltDB *temp = begin;
    EltDB *new = malloc(sizeof(EltDB*));
    while(temp->next != NULL && strcmp(temp->name,name)<0)
    {
        temp = temp->next;  
    }
    if(strcmp(temp->name,name) != 0)
    {
        strcpy(new->name, name);
        new->next = temp;
        temp->old = new;
        return 1;
    }
    if(strcmp(temp->next->name,name)!= 0)
    {
        strcpy(new->name,name);
        new->next = temp->next;
        temp->next->old = new;
        return 1;
    }
    if(strcmp(temp->name,name) == strcmp(temp->next->name,name))
    {
        return 0;
    }
    strcpy(new->name, name);
    new->next = NULL;
    new->old = temp->next;
    return 1;
    
}

int supp_eltDB(EltDB *begin, gchar *name)
{
    EltDB *temp = begin;
    while (temp != NULL && strcmp(temp->name,name)<0)
    {
        temp = temp->next;
    }
    if (temp == NULL || strcmp(temp->name,name)!=0)
    {
        return 0;
    }
    temp->old->next = temp->next;
    free(temp);
    return 1;  
}

EltDB* search_EltDB(EltDB *begin, gchar *name)
{
    EltDB *temp = begin;
    while(temp != NULL && strcmp(temp->name,name) < 0)
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    init_sdl();
    EltDB *begin = malloc(sizeof(EltDB*));
    initializeDB(begin);   
}
