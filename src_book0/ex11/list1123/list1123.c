#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#define QUALITY 90

int main(int argc, char* argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s IN_FILE OUT_FILE", argv[0]);
    exit(1);
  }

  GdkPixbuf* srcbuf;
  GdkPixbuf* dstbuf;
  GError* error = NULL;
  int w, h;

  // Initialize
  gtk_init(&argc, &argv);

  // read image
  if ((srcbuf = gdk_pixbuf_new_from_file(argv[1], &error)) == FALSE) {
    fprintf(stderr, "Cannot read image: %s\n", argv[1]);
    exit(1);
  }
  w = gdk_pixbuf_get_width(srcbuf);
  h = gdk_pixbuf_get_height(srcbuf);

  // resize
  dstbuf = gdk_pixbuf_scale_simple(srcbuf, w/2, h/2, GDK_INTERP_BILINEAR);

  // write image data to file
  if (gdk_pixbuf_save(dstbuf, argv[2], "jpeg", &error, "quality", "90", NULL)
      == FALSE) {
    fprintf(stderr, "Cannot write image: %s\n", argv[2]);
    exit(1);
  }

  // finalize to finish
  gdk_pixbuf_unref(srcbuf);
  gdk_pixbuf_unref(dstbuf);
  return 0;
}
