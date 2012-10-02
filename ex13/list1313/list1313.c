#include <cairo/cairo-svg.h>
#include <math.h>

#define SVG_WIDTH 500
#define SVG_HEIGHT 500
#define SVG_RADIUS 200
#define SVG_FILE "test.svg"

int main(int argc, char* argv[]) {
  cairo_surface_t* svg = cairo_svg_surface_create(SVG_FILE, SVG_WIDTH, SVG_HEIGHT);
  cairo_t* cr = cairo_create(svg);
  double angle, x, y;

  /* weight of the line */
  cairo_set_line_width(cr, 10);

  /* draw star */
  cairo_move_to(cr, 250, 50);
  for (angle = 90.0; angle <= 810.0; angle += 144.0) {
    x = SVG_WIDTH/2 + SVG_RADIUS * cos(angle * M_PI / 180.0);
    y = SVG_HEIGHT/2 - SVG_RADIUS * sin(angle * M_PI / 180.0);
    cairo_line_to(cr, x, y);
  }
  cairo_close_path(cr);
  cairo_stroke(cr);

  /* finalize(file output) */
  cairo_destroy(cr);
  cairo_surface_destroy(svg);

  return 0;
}
