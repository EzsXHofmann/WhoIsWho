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
    char *path = "../img/faces/yalefacesgood"; 
    //GError **error = malloc(sizeof(GError*)); 
    GDir* dir = g_dir_open(path, 0, NULL);
    G_CONST_RETURN gchar* file = g_dir_read_name(dir);
    FILE *fichier = fopen("test","r+");
    while (file != NULL && begin)
    {
        //strcpy(begin->name,(char*)file);
        begin->name = (char*)file;
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
    char *str = malloc(sizeof(char));
    char *new = malloc(sizeof(char)*50);
    new = "";
    FILE *fichier = fopen(filename,"r+");
    FILE *file = fopen("test_final","r+");
    while ((*str = fgetc(fichier))!=EOF)
    {      
        if(*str == '/')
        {
            begin->name = new;
            fputs(begin->name,file);//SETFAULT
            new = "";
        }
        else if(*str == '\n')
        {
            printf("\n");
            begin->next = malloc(sizeof(EltDB));
            begin = begin->next;
            begin->old = begin;
            begin->eigen = atoi(new);
            fputc(begin->eigen,file);
            new = "";
        }
        else
        {
           strcat(new,str);//SETFAULT   
        }
    }
    begin->next = NULL;
    begin = temp;
    
}

/*void Write(EltDB *begin)
{
    EltDB *temp = begin;
    FILE *fichier = fopen("test_final","r+");
    while(begin)
    {
        printf("boucle\n");
        //printf("%s\n",begin->name);
        fputs(begin->name,fichier);
        printf("fputs(begin->name,fichier)\n");
        //fputc(temp->eigen,fichier);
        begin = begin->next;
        printf("begin = begin->next\n");
    }
    begin = temp;
}*/
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
    Update("test",begin);
    //Write(begin);
}
