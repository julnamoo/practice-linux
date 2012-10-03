#include <stdlib.h>
#include "cvxnode.h"

CvxNode* cvx_node_new(CvxField* field, gint x, gint y) {
  CvxNode* retvar;

  retvar = (CvxNode*) malloc(sizeof(CvxNode));
  if (retvar == NULL) return NULL;

  retvar->field = field;
  retvar->x = x;
  retvar->y = y;
  retvar->width = CVX_NODE_DEFAULT_WIDTH;
  retvar->height = CVX_NODE_DEFAULT_HEIGHT;
  return retvar;
}

void cvx_node_render(CvxNode* node, cairo_t* cr) {
  double ulx = node->x - node->width / 2.0;
  double uly = node->y - node->height / 2.0;

  cairo_set_line_width(cr, CVX_NODE_LINE_WIDTH);

  cairo_set_source_rgb(cr, 0.0, 1.0, 1.0);
  cairo_rectangle(cr, ulx, uly, node->width, node->height);
  cairo_fill_preserve(cr);
  cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
  cairo_stroke(cr);
}
