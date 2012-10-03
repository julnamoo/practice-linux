#ifndef __CVX__NODE_H__
#define __CVX__NODE_H__
#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _CvxNode CvxNode;

#include "cvxfield.h"

struct _CvxNode {
  CvxField* field;
  gint x, y;
  guint width, height;
  gint dx, dy;
};

#define CVX_NODE_DEFAULT_WIDTH 8
#define CVX_NODE_DEFAULT_HEIGHT 8

#define CVX_NODE_LINE_WIDTH 1.0

CvxNode* cvx_node_new(CvxField* field, gint x, gint y);
void cvx_node_render(CvxNode* node, cairo_t* cr);
gboolean cvx_node_is_inside_p(CvxNode* node, gint x, gint y);
void cvx_node_move_to(CvxNode* node, gint x, gint y);
void cvx_node_set_difference(CvxNode* node, gint x, gint y);

G_END_DECLS

#endif // __CVX_NODE_H__
