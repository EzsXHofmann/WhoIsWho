#include <stdlib.h>
#include <gtk/gtk.h>
#include "base.h"
#include "base.c"

void Create_window()
{
    GtkWidget* MainWindow = NULL;
    gtk_init(&argc,&argv);
    MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWindow* fenetre = GTK_WINDOW(MainWindow);
    gtk_window_set_title(fenetre,"WhoIsWho");
    gchar* titre = "WhoIsWho"; // gtk_window_get_title(GTK_WINDOW(fenetre));
    gint width = 800;
    gint height = 550;
    gtk_window_set_default_siez(fenetre,width,height); // Taille par default(resize auto)
    gtk_window_resize(fenetre,width,height); // Taille actuelle
    gtk_window_move(fenetre,GTK_WIN_POS_CENTER); // Ouverture au milieu de l'écran
    gboolean icone = gtk_window_set_icon_from_file   (GtkWindow *window, const gchar *filename, GError **err);// tente de mettre une icone
    gtk_window_iconify (fenetre);//iconifier
    GtkWidget* bouton =  gtk_button_new_with_mnemonic ("Ajouter à la Base de donnée");//ajouter un bouton
    if (user_function (bouton,GDK_BUTTON_PRESS, malloc(sizeof(gpointer)))) // si bouton press
    {
        
    }
    g_signal_connect(G_OBJECT(MainWindow),"delete-event",G_CALLBACK(gtk_main_quit),NULL);
    gtk_widget_show(GtkWidget *widget); //show window
    gtk_main();
    return EXIT_SUCCESS;
}

int main()
{
    Create_window();
}
