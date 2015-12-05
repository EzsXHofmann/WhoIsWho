#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <glib/gdir.h>
#include <string.h>
#include "base.h"

void initializeEltDB(EltDB *begin)
{
    EltDB *temp = begin;
    begin->old = NULL;
    char *path = "../img/"; 
    GError **error = malloc(sizeof(GError*));
    printf("0 \n");
    GDir* dir = g_dir_open(path, 0, error);
    printf("1\n");
    G_CONST_RETURN gchar* file = g_dir_read_name(dir);
    printf("2\n");
    FILE *fichier = fopen("test","r+");
    while (file != NULL)
    {
        strcpy(begin->name, file);
        fputs(begin->name,fichier);
        fputc('/',fichier);
        fputs("2555",fichier);
        fputc('\n',fichier);
        begin->next = malloc(sizeof(EltDB));
        begin = begin->next;
        begin->old = begin;
        file = g_dir_read_name(dir);
    }
    begin =temp;  
}

void Update(char* filename,EltDB *begin)
{
    EltDB *temp = begin;
    char str;
    char* new = "";
    FILE *fichier = fopen(filename,"r+");
    while ((str = fgetc(fichier))!=EOF)
    {   
        if(str == '/')
        {
            begin->name = new;
            new = "";
        }
        else if(str == '\n')
        {
            begin->next = malloc(sizeof(EltDB*));
            begin = begin->next;
           // begin->eigen = atoi(new);
            new = "";
        }
        else
        {
            new = strcat(new,&(str));
        }
    }
    begin = temp;
}

void Write(EltDB *begin)
{
    EltDB *temp = begin;
    FILE *fichier = fopen("test_final","r+");
    while(temp)
    {
        fputs(temp->name,fichier);
        //fputc(temp->eigen,fichier);
        temp = temp->next;
    }
}
int ajout_eltDB(EltDB *begin, gchar *name)
{
    EltDB *temp = begin;
    EltDB *new = malloc(sizeof(EltDB));
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
    EltDB *begin = malloc(sizeof(EltDB));
    initializeEltDB(begin);
    //Update("test",begin);
    //Write(begin);
}
