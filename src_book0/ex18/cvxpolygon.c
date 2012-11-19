#include <stdlib.h>
#include "cvxpolygon.h"

CvxPolygon* cvx_polygon_new(CvxField* field, GList* nodes) {
  CvxPolygon* retvar;

  retvar = (CvxPolygon*) malloc(sizeof(CvxPolygon));
  if (retvar == NULL) return NULL;

  retvar->field = field;
  retvar->nodes = filed->node_list->nodes;

  return retvar;
}

void cvx_polygon_render(CvxPolygon* polygon, cairo_t* cr) {
  GList* arg_list = polygon->nodes;
  cairo_set_line_width(cr, CVX_POLYGON_LINE_WIDTH);
  cairo_set_source_rgb(cr, 1.0, 5.0, 0.0);

  while (arg_list != NULL) {
    CvxNode* arg = (CvxNode*) (arg_list->data);
    cairo_line_to(cr, arg->x, arg->y);
    arg_list = g_list_next(arg_list);
  }
  cairo_close_path(cr);
  cairo_stroke_preserve(cr);
  cairo_set_source_rgb(cr, 1.0, 1.0, 0.5);
  cairo_fill(cr);
}
