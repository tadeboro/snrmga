/*
** Copyright (C) 2009 Tadej Borovšak <tadeboro@gmail.com>
**  
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software 
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/* This is autotools-generated file that will hold macros like
 * GETTEXT_PACKAGE etc. */
#include <config.h>

/* Include here is needed for internationalization macros _(), N_() ... */
#include <glib/gi18n.h>
/* Include GTK+ header */
#include <gtk/gtk.h>

/* Define structure that will hold data, shared among all callback functions */
typedef struct _Data Data;
struct _Data
{
  GtkWidget *main_window,
	    *image;
};


/* Simple callback functions */
G_MODULE_EXPORT void
cb_clicked_unset_image (GtkButton *button,
			Data      *data)
{
#ifdef ENABLE_DEBUG
  g_print ("Inside 'cb_clicked_unset_image\n");
#endif

  gtk_image_set_from_pixbuf (GTK_IMAGE (data->image), NULL);
}

G_MODULE_EXPORT void
cb_clicked_set_image_a (GtkButton *button,
			Data      *data)
{
  char *path = g_build_filename (PKGPIXMAPSDIR, "image_a.png", NULL);

#ifdef ENABLE_DEBUG
  g_print ("Inside 'cb_clicked_set_image_a\n");
#endif

  gtk_image_set_from_file (GTK_IMAGE (data->image), path);
  g_free (path);
}

G_MODULE_EXPORT void
cb_clicked_set_image_b (GtkButton *button,
			Data      *data)
{
  char *path = g_build_filename (PKGPIXMAPSDIR, "image_b.png", NULL);

#ifdef ENABLE_DEBUG
  g_print ("Inside 'cb_clicked_set_image_b\n");
#endif

  gtk_image_set_from_file (GTK_IMAGE (data->image), path);
  g_free (path);
}


/* Main function */
int
main (int    argc,
      char **argv)
{
  Data       *data;
  char       *path;
  GtkBuilder *builder;
  GError     *error = NULL;

  /* Initialize translation machinery */
  bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);

  /* Initialize GTK+ */
  gtk_init (&argc, &argv);

#ifdef ENABLE_DEBUG
  g_print ("Running application in debug mode\n");
#endif

  /* Allocate shared data memory */
  data = g_slice_new0 (Data);

  /* Create UI */
  builder = gtk_builder_new ();
  path = g_build_filename (PKGUIDIR, "snrmga.glade", NULL);
  if (!gtk_builder_add_from_file (builder, path, &error))
    {
      g_critical ("%s", error->message);

      return 1;
    }
  g_free (path);

#define GW(name) \
  (data->name = GTK_WIDGET (gtk_builder_get_object (builder, (#name))))
  GW (main_window);
  GW (image);
#undef GW

  gtk_builder_connect_signals (builder, data);
  g_object_unref (builder);

  gtk_widget_show (data->main_window);

  gtk_main();

  return 0;
}
