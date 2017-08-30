/* This is the official frontend for Winter-Terminal by Joaquin Crespo. */
/* This is in 0.2.1 BETA */
/* This program are licensed in GPLv3*/
/* The name is for the Nightwish song, the best ever */

/* Winter and gtk+3 libs*/
#include "../winter-lib.h" /* For all functions */
#include <gtk/gtk.h> /* Gtk support */

static void user (GtkWidget *widget, gpointer data){
  check_user();
}



int main (int   argc, char *argv[]){
  GtkBuilder *builder; /* The module that buld the GUI */
  GObject *window; /* The creation of the Window*/
  GObject *button; /* The button. This is an object, so he can be more than one.*/

  gtk_init (&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "builder.ui", NULL);

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "Winter-terminal");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  /* First Button*/

  button = gtk_builder_get_object (builder, "Check if you are root"); /* The label of the button */
  g_signal_connect (button, "clicked", G_CALLBACK (user), NULL); /* Call to user function when is clicked */

  /* Second Button */

  button = gtk_builder_get_object (builder, "Button 2");
  g_signal_connect (button, "clicked", G_CALLBACK (user), NULL);

  /* The Exit button */
  button = gtk_builder_get_object (builder, "Quit");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

  gtk_main(); /* This init the GTK */
  return 0;
}
