#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef struct bt_node {
  struct bt_node *left;
  struct bt_node *right;
  int value;
} bt_node_t;

bt_node_t *bt_insert(bt_node_t *root, int value);
bt_node_t *bt_erase(bt_node_t *root, int value);
void bt_walk(bt_node_t *root);
void bt_free(bt_node_t *root);
bt_node_t *bt_search(bt_node_t *root, int value);

#endif

/* vim: set nu ts=2 sw=2 si et : */
