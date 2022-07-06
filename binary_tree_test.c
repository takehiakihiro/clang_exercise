#include "binary_tree.h"
#include <stdio.h>

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
  printf("search 6 %p\n", bt_search(root, 6));
  printf("search 4 %p\n", bt_search(root, 4));
  printf("search 8 %p\n", bt_search(root, 8));
  printf("search 100 %p\n", bt_search(root, 100));
  printf("search 5 %p\n", bt_search(root, 5));
  printf("search 15 %p\n", bt_search(root, 15));
  printf("search 3 %p\n", bt_search(root, 3));
  printf("search 9 %p\n", bt_search(root, 9));
  printf("\n");

  bt_eject(root, 5);
  bt_eject(root, 15);
  bt_eject(root, 3);
  bt_eject(root, 9);

  printf("\n");
  printf("search 6 %p\n", bt_search(root, 6));
  printf("search 4 %p\n", bt_search(root, 4));
  printf("search 8 %p\n", bt_search(root, 8));
  printf("search 100 %p\n", bt_search(root, 100));
  printf("search 5 %p\n", bt_search(root, 5));
  printf("search 15 %p\n", bt_search(root, 15));
  printf("search 3 %p\n", bt_search(root, 3));
  printf("search 9 %p\n", bt_search(root, 9));
  printf("\n");

  bt_walk(root);

  bt_free(root);

  return 0;
}

/* vim: set nu ts=2 sw=2 si et : */
