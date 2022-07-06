#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef struct bt_node {
  struct bt_node *left;
  struct bt_node *right;
  int value;
} bt_node_t;


bt_node_t *bt_insert(bt_node_t *cur, int value);
bt_node_t *bt_eject(bt_node_t *cur, int value);
void bt_walk(bt_node_t *cur);
void bt_free(bt_node_t *cur);

#endif

/* vim: set nu ts=2 sw=2 si et : */
