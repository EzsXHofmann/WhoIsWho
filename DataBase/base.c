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
    temp->eigen = 0;
    temp->next = malloc(sizeof(EltDB));
    temp->old = NULL;
    temp = temp->next;
    char *path = "img/faces";
    GDir* dir = g_dir_open(path, 0, NULL);
    G_CONST_RETURN gchar* file = g_dir_read_name(dir);
    FILE *fichier = fopen("DataBase/test", "r+");
    while (file != NULL && temp)
    {
        (begin->eigen)++;
        temp->name = (char *)file;
        fputs(temp->name, fichier);
        fputs("/2555\n", fichier);
        temp->next = malloc(sizeof(EltDB));
        temp->next->old = temp;
        temp = temp->next;
        file = g_dir_read_name(dir);
    }
    temp->next = NULL;
}

char* catstr(char *new, char str, char *s)
{
    int i = 0;
    while (*new != '\0')
    {
        s[i] = *new;
        i++;
        new++;
    }
    s[i] = str;
    s[i+1] = '\0';
    return s;
}

EltDB* Initialize()
{
    EltDB *begin = malloc(sizeof(EltDB));
    begin->eigen = 0;
    EltDB *temp = begin;
    temp->next = malloc(sizeof(EltDB));
    temp->next->old = temp;
    temp = temp->next;

    char s[99];
    char str;
    char *new = malloc(sizeof(char)*50);
    new = "";

    FILE *fichier = fopen("DataBase/test", "r+");
    FILE *file = fopen("DataBase/test_final", "r+");

    while ((str = fgetc(fichier)) != EOF)
    {      
        if (str == '/')
        {
            temp->name = new;
            fputs(temp->name, file);
            fputc('/',file);
            new = "";
        }

        else if (str == '\n')
        {   
            (begin->eigen)++;
            temp->next = malloc(sizeof(EltDB));
            temp->next->old = temp;
            temp = temp->next;
            temp->eigen = atoi(new);
            fprintf(file, "%d\n", temp->eigen);
            new = "";
        }

        else
           new = catstr(new, str, s);
    }

    temp->next = NULL;

    return begin;
}

int ajout_eltDB(EltDB *begin, gchar *filename)
{
    FILE *file = fopen("DataBase/test", "a");
    EltDB *temp = begin->next;
    
    while (temp->next != NULL && strcmp(temp->name, filename) != 0)
        temp = temp->next;

    if (strcmp(temp->name, filename) != 0)
    {
        temp->next = malloc(sizeof(EltDB));
        temp->next->old = temp;
        temp = temp->next;
        temp->eigen = 2555;
        strcpy(temp->name, filename);
        (begin->eigen)++;
        fputs(temp->name, file);
        fprintf(file, "%d\n", temp->eigen);
        return 1;
    }

    return 0;
}

/*int supp_eltDB(EltDB *begin, gchar *name)
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
}*/

/*EltDB* search_EltDB(EltDB *begin, gchar *name)
{
    EltDB *temp = begin;
    while(temp != NULL && strcmp(temp->name,name) < 0)
    {
        temp = temp->next;
    }
    return temp;
}*/

/*int main()
{
    EltDB *begin = malloc(sizeof(EltDB));
    initializeEltDB(begin);
    Update(begin);
}*/
