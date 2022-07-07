#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 二分木要素追加
 */
bt_node_t *bt_insert(bt_node_t *cur, int value)
{
  if (NULL == cur) {
    /* 末端まで到達して値がないので新規登録場所に到達した */
    cur = (bt_node_t *)malloc(sizeof(bt_node_t));
    if (NULL == cur) {
      /* エラー発生 */
      return NULL;
    }
    cur->left = NULL;
    cur->right = NULL;
    cur->value = value;
    /* ここから再起呼び出しがすべて折り返す */
  }
  else if (value < cur->value) {
    /* 現在の位置のノードの値よりも新規のノードの値が小さいので左側に登録 */
    /* 再起呼び出し */
    cur->left = bt_insert(cur->left, value);
  }
  else {
    /* 現在の位置のノードの値よりも新規のノードの値が大きいので右側に登録 */
    /* 再起呼び出し */
    cur->right = bt_insert(cur->right, value);
  }

  return cur;
}

/**
 * @brief 二分木要素検索
 * @return 見つかったノードへのポインタ
 */
bt_node_t *bt_search(bt_node_t *cur, int value)
{
  if (NULL == cur) {
    /* 一致する値を探したが、存在しないので終わり */
    return NULL;
  }

  if (value < cur->value) {
    return bt_search(cur->left, value);
  }
  else if (value > cur->value) {
    return bt_search(cur->right, value);
  }

  return cur;
}

/**
 * @brief 一番大きい値を持つノードを返す
 */
static bt_node_t *bt_get_max(bt_node_t *node)
{
  while (NULL != node && NULL != node->right) {
    node = node->right;
  }
  return node;
}

/**
 * @brief 二分木要素削除
 * @return ノードへのポインタ
 */
bt_node_t *bt_erase(bt_node_t *cur, int value)
{
  bt_node_t *ret = NULL;

  if (NULL == cur) {
    /* 一致する値を探したが、存在しないので終わり */
    return NULL;
  }

  if (value < cur->value) {
    cur->left = bt_erase(cur->left, value);
    return cur;
  }
  else if (value > cur->value) {
    cur->right = bt_erase(cur->right, value);
    return cur;
  }

  /* 値が一致するノードが見つかったのでメモリを解放 */
  if (NULL == cur->left) {
    /* leftがNULLなのでrightがそのままcurの位置に移動する */
    ret = cur->right;
    free(cur);
  }
  else if (NULL == cur->right) {
    /* rightがNULLなのでleftがそのままcurの位置に移動する */
    ret = cur->left;
    free(cur);
  }
  else {
    /* 両方にデータが存在するので、leftの一番大きい値を探して付け替える */
    ret = bt_get_max(cur->left);
    cur->value = ret->value;
    /* 値を入れ替えたので、対象の場所を削除する */
    cur->left = bt_erase(cur->left, ret->value);
    ret = cur;
  }
  return ret;
}

/**
 * @brief 二分木巡回
 */
void bt_walk(bt_node_t *cur)
{
  if (cur == NULL) {
    printf("leaf;\n");
    return;
  }
  printf("{\n");
  bt_walk(cur->left);
  printf("}\n");
  printf("value = %d;\n", cur->value);
  printf("[\n");
  bt_walk(cur->right);
  printf("]\n");
}

/**
 * @brief 全削除
 */
void bt_free(bt_node_t *cur)
{
  if (NULL != cur) {
    /* 左側を全部消す */
    bt_free(cur->left);

    /* 左側を全部消す */
    bt_free(cur->right);

    free(cur);
  }
}

/* vim: set nu ts=2 sw=2 si et : */
