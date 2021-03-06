#include <gtk/gtk.h>

int main( int argc, char *argv[])
{
    GtkWidget *window, *image;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
    gtk_window_set_title(GTK_WINDOW(window), "Image");
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    gtk_container_set_border_width(GTK_CONTAINER(window), 2);

    image = gtk_image_new_from_file("images/testimage.jpg");
    gtk_container_add(GTK_CONTAINER(window), image);


    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
