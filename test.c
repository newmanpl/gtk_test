#include <gtk/gtk.h>
typedef struct _myst {
  int id;
  char* desc;
}myst_;

void destroy(GtkWidget *widget, gpointer data)
{
    myst_  *d =(myst_ *) data;
    printf("\033[22;34m %s %d %s data.id %d data.desc %s \033[0m\n", __FILE__,__LINE__,__FUNCTION__, d->id, d->desc);
    gtk_main_quit();
}

int main (int argc, char *argv[])
{
    GtkWidget *window;
    myst_ st;
    st.id = 10;
    st.desc = "description";
    
    /* Initialize the GTK+ and all of its supporting libraries. */
    gtk_init (&argc, &argv);
    /* Create a new window, give it a title and display it to the user. */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Hello beirong's World");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_resize(GTK_WINDOW(window), 100,100);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), &st);

    gtk_widget_show (window);

    /* Hand control over to the main loop. */
    gtk_main ();
    return 0;
}
