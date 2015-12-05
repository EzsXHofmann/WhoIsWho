# include <stdlib.h>
# include <gtk/gtk.h>
/*#include "../Database/base.h"
#include "../Database/base.c"*/

int main(int argc, char **argv)
{
    //VARIABLE
    gtk_init(&argc,&argv);
    GtkWidget* MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWindow* fenetre = GTK_WINDOW(MainWindow);
    gtk_window_set_title(fenetre,"WhoIsWho");
    gchar* titre = "WhoIsWho"; // gtk_window_get_title(GTK_WINDOW(fenetre));
    gint width = 800;
    gint height = 550;
    
    //SETUP WINDOW
    gtk_window_set_default_size(fenetre,width,height); // Taille par default(resize auto)
    gtk_window_resize(fenetre,width,height); // Taille actuelle
    gtk_window_set_position(fenetre,GTK_WIN_POS_CENTER); // Ouverture au milieu de l'écran
    gboolean icone = gtk_window_set_icon_from_file(fenetre, "logo.jpg", NULL);// tente de mettre une icone
    gtk_window_iconify(fenetre);//iconifier
    GtkWidget* bouton =  gtk_button_new_with_label("Ajouter à la Base de donnée");//ajouter un bouton
    GtkWidget * file_button = gtk_file_chooser_button_new("Select a picture",GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
        
    //EVENT
    g_signal_connect(G_OBJECT(MainWindow),"delete-event",G_CALLBACK(gtk_main_quit),NULL);
    
    //ADD TO WINDOW
    gtk_container_add(GTK_CONTAINER(MainWindow),bouton);
    gtk_widget_show(MainWindow); //show window
    gtk_main();
    return EXIT_SUCCESS;
}
