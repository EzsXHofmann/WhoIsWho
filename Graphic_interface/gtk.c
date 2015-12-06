# include <stdlib.h>
# include <stdio.h>
# include <gtk/gtk.h>
/*#include "../Database/base.h"
#include "../Database/base.c"*/

//gcc -o gtk gtk.c `pkg-config --libs --cflags gtk+-2.0`
void ajouter_img(gpointer user_data)
{
   FILE* file = fopen("test","r+");
   fputs((char*)user_data,file);
   fputc('\n',file);
}

void button_ajout(GtkWidget* window)
{
    GtkWidget *bouton = gtk_button_new_with_label("Ajouter à la DATABASE");
    GtkWidget* bouton2 = gtk_button_new_with_label("       Detecter Visage       ");
    GtkWidget * bouton3 = gtk_file_chooser_button_new("      JOINDRE FICHIER      ",GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER(bouton3),"/home/hamza/Images");
    gchar * filename = gtk_file_chooser_get_current_folder (GTK_FILE_CHOOSER(bouton3));
    gchar * filename2 = gtk_file_chooser_get_uri(GTK_FILE_CHOOSER(bouton3));
    g_print("%s\n",(char*)filename);
    g_print("%s\n",(char*)filename2);
    GtkWidget* table = gtk_table_new(3,3,TRUE);
    gtk_container_add(GTK_CONTAINER(window),GTK_WIDGET(table));
    gtk_table_attach(GTK_TABLE(table),bouton,3,4,3,4,GTK_EXPAND,GTK_EXPAND,0,0);
    gtk_table_attach(GTK_TABLE(table),bouton2,3,4,4,5,GTK_EXPAND,GTK_EXPAND,0,0);
    gtk_table_attach(GTK_TABLE(table),bouton3,3,4,5,6,GTK_EXPAND,GTK_EXPAND,0,0);
    g_signal_connect(G_OBJECT(bouton),"clicked",G_CALLBACK(ajouter_img),gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(bouton3)));
    gtk_widget_show_all(window);
    gtk_main();
}


void initialize_window(GtkWindow* fenetre)
{
    gtk_window_set_title(fenetre,"WhoIsWho");
    gint width = 800;
    gint height = 550;
    gtk_window_set_default_size(fenetre,width,height); // Taille par default(resize auto)
    gtk_window_resize(fenetre,width,height); // Taille actuelle
    gtk_window_set_position(fenetre,GTK_WIN_POS_CENTER); // Ouverture au milieu de l'écran
    gboolean icone = gtk_window_set_icon_from_file(fenetre, "logo.jpg", NULL);// tente de mettre une icone
    if(icone)
    {
        gtk_window_iconify(fenetre);//iconifier
    }
}
int main(int argc, char **argv)
{
    //VARIABLE
    gtk_init(&argc,&argv);
    GtkWidget* MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWindow* fenetre = GTK_WINDOW(MainWindow);
    
    //SETUP WINDOW
    
    initialize_window(fenetre);
          
    //EVENT
    g_signal_connect(G_OBJECT(MainWindow),"delete-event",G_CALLBACK(gtk_main_quit),NULL);
    
    //gtk_container_add(GTK_CONTAINER(MainWindow),file_button);
    /*gtk_widget_show_all(MainWindow); //show window
    gtk_main();*/
    button_ajout(MainWindow);
    return EXIT_SUCCESS;
}

/*int main(int argc, char** argv)
{
    gtk_init(&argc,&argv);
    GtkWidget *window,*bouton;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    bouton = gtk_button_new_with_label("Ajouter");
    g_signal_connect(G_OBJECT(window),"delete-event",G_CALLBACK(gtk_main_quit),NULL);
    gtk_container_add(GTK_CONTAINER(window),bouton);
    gtk_widget_show_all(window); //show window
    gtk_main();
    return EXIT_SUCCESS;

}*/
