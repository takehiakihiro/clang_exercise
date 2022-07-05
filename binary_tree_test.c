#include <stdio.h>
#include "binary_tree.h"

/**
 * @brief main
 */
int main(void)
{
  bt_node_t *root = NULL;

  bt_insert(&root, 5);
  bt_insert(&root, 3);
  bt_insert(&root, 1);
  bt_insert(&root, 15);
  bt_insert(&root, 12);
  bt_insert(&root, 19);
  bt_insert(&root, 10);
  bt_insert(&root, 8);
  bt_insert(&root, 9);
  bt_insert(&root, 4);

  bt_walk(root);

  return 0;
}

/* vim: set nu ts=2 sw=2 si et : */
