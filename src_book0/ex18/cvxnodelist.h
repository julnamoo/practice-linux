#ifndef __CVX_NODE_LIST_H__
#define __CVX_NODE_LIST_H__
#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _CvxNodeList CvxNodeList;
#include "cvxfield.h"

struct _CvxNodeList {
  CvxField* field;
  GList* nodes;
};

#define CVX_NODE_LIST_NODES_NUM 30

CvxNodeList* cvx_node_list_new(CvxField* field, guint max_x, guint max_y);
CvxNode* cvx_node_list_pick_node(CvxNodeList* node_set, gint x, gint y);
void cvx_node_list_render(CvxNodeList* node_set, cairo_t* cr);

G_END_DECLS

#endif // __CVX_NODE_LIST_H__
