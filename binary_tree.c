#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

/**
 * @brief 二分木要素追加
 */
int bt_insert(bt_node_t **node, int value)
{
  bt_node_t *cur = *node;
  if (cur == NULL) {
    /* 末端まで到達して値がないので新規登録場所に到達した */
    cur = (bt_node_t *)malloc(sizeof(bt_node_t));
    if (cur == NULL) {
      /* エラー発生 */
      return -1;
    }
    cur->left = NULL;
    cur->right = NULL;
    cur->value = value;
    *node = cur;
    /* ここから再起呼び出しがすべて折り返す */
    return 0;
  }

  if (value < cur->value) {
    /* 現在の位置のノードの値よりも新規のノードの値が小さいので左側に登録 */
    /* 再起呼び出し */
    return bt_insert(&cur->left, value);
  }
  /* 現在の位置のノードの値よりも新規のノードの値が大きいので右側に登録 */
  /* 再起呼び出し */
  return bt_insert(&cur->right, value);
}

/**
 * @brief 二分木要素削除
 */
int bt_eject(bt_node_t **cur, int value)
{
}

/**
 * @brief 二分木巡回
 */
void bt_walk(bt_node_t *cur)
{
  if (cur == NULL) {
    return;
  }
  bt_walk(cur->left);
  printf("value=%d\n", cur->value);
  bt_walk(cur->right);
}

/**
 * @brief 全削除
 */
void bt_delete(bt_node_t *cur)
{
}

/* vim: set nu ts=2 sw=2 si et : */
