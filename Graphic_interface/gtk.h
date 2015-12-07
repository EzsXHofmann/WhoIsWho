# include <stdlib.h>
# include <stdio.h>
# include "../DataBase/base.h"

extern EltDB *begin;
extern GtkWidget *mainwindow;

gchar* get_filename(gchar* name);

int goodformat(gchar *path);

void ajouter_img(GtkWidget *bouton3, gpointer window);

void button_ajout(GtkWidget *window, EltDB *sent);

void initialize_window(GtkWindow *fenetre);


