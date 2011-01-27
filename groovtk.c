#include <gtk/gtk.h>
#include <webkit/webkit.h>

static void 
destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char **argv)
{
  gtk_init(&argc, &argv);

  GtkWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  GtkWidget *web_view = webkit_web_view_new();

  gtk_container_add(GTK_CONTAINER(scrolled_window), web_view);
  gtk_container_add(GTK_CONTAINER(main_window), scrolled_window);

  webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web_view), "http://www.grooveshark.com");

  g_signal_connect (main_window, "destroy", G_CALLBACK(destroy), NULL);

  gtk_widget_show_all(main_window);
  gtk_main();

  return 0;
}
