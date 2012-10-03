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

gboolean cvx_node_is_inside_p(CvxNode* node, gint x, gint y) {
  double ulx = node->x - node->width/2.0;
  double uly = node->y - node->height/2.0;
  double lrx = node->x + node->width/2.0;
  double lry = node->y + node->height/2.0;
  
  return ((ulx < x) && (x < lrx)) && ((uly < y) && (y < lry));
}

void cvx_node_move_to(CvxNode* node, gint x, gint y) {
  node->x = x + node->dx;
  node->y = y + node->dy;
}

void cvx_node_set_difference(CvxNode* node, gint x, gint y) {
  node->dx = node->x - x;
  node->dy = node->y - y;
}
