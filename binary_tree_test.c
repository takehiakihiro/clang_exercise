#include <stdio.h>
#include "binary_tree.h"

/**
 * @brief main
 */
int main(void)
{
  bt_node_t *root = NULL;

  root = bt_insert(root, 5);
  root = bt_insert(root, 3);
  root = bt_insert(root, 1);
  root = bt_insert(root, 15);
  root = bt_insert(root, 12);
  root = bt_insert(root, 19);
  root = bt_insert(root, 10);
  root = bt_insert(root, 8);
  root = bt_insert(root, 9);
  root = bt_insert(root, 4);
  root = bt_insert(root, 13);
  root = bt_insert(root, 14);

  bt_walk(root);

  printf("\n");

  bt_eject(root, 5);
  bt_eject(root, 15);
  bt_eject(root, 3);
  bt_eject(root, 9);

  bt_walk(root);

  bt_free(root);

  return 0;
}

/* vim: set nu ts=2 sw=2 si et : */
