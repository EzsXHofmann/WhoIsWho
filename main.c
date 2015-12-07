# include <stdlib.h>
# include <stdio.h>
# include <gtk/gtk.h>
# include "DataBase/base.h"
# include "Graphic_interface/gtk.h"

int main(int argc, char **argv)
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

