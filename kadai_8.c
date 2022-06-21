#include <stdio.h>
#include <stdlib.h>

/**
 * リンクリストの各ノード
 */
typedef struct node {
  int key;
  int value;
  struct node *next;
} node_t;

/**
 * リンクリスト
 */
typedef struct linked_list {
  node_t *front;
} linked_list_t;

/* リンクリストの一番最後に追加 */
int push_back(linked_list_t *linked_list, int key, int value);
/* リンクリストの一番先頭に追加 */
int push_front(linked_list_t *linked_list, int key, int value);
/* リンクリストの一番後ろを削除 */
void pop_back(linked_list_t *linked_list);
/* リンクリストの一番先頭を削除 */
void pop_front(linked_list_t *linked_list);
/* リンクリストに、keyでソートされた位置（昇順）に追加 */
int sorted_insert(linked_list_t *linked_list, int key, int value);
/* リンクリストのすべての要素を出力 */
void show(const linked_list_t *linked_list);
/* リンクリストの要素をすべて解放 */
void clear(linked_list_t *linked_list);

int main(void)
{
  linked_list_t linked_list = { NULL };

  push_back(&linked_list, 3, 4);
  show(&linked_list);
  push_back(&linked_list, 2, 10);
  show(&linked_list);
  push_back(&linked_list, 5, 20);
  show(&linked_list);
  push_back(&linked_list, 1, 0);
  show(&linked_list);
  push_back(&linked_list, -1, -100);
  show(&linked_list);

  pop_front(&linked_list);
  show(&linked_list);
  pop_front(&linked_list);
  show(&linked_list);
  pop_front(&linked_list);
  show(&linked_list);
  pop_front(&linked_list);
  show(&linked_list);
  pop_front(&linked_list);
  show(&linked_list);

  clear(&linked_list);

  push_front(&linked_list, 30, 12);
  show(&linked_list);
  push_front(&linked_list, 100, 120);
  show(&linked_list);
  push_front(&linked_list, 3, 2);
  show(&linked_list);
  push_front(&linked_list, -100, 1000);
  show(&linked_list);

  pop_back(&linked_list);
  show(&linked_list);
  pop_back(&linked_list);
  show(&linked_list);
  pop_back(&linked_list);
  show(&linked_list);
  pop_back(&linked_list);
  show(&linked_list);
  pop_back(&linked_list);
  show(&linked_list);

  clear(&linked_list);

  sorted_insert(&linked_list, 1, 1);
  show(&linked_list);
  sorted_insert(&linked_list, 2, 2);
  show(&linked_list);
  sorted_insert(&linked_list, 3, 3);
  show(&linked_list);
  sorted_insert(&linked_list, 4, 4);
  show(&linked_list);
  sorted_insert(&linked_list, 4, -4);
  show(&linked_list);
  sorted_insert(&linked_list, 1, -1);
  show(&linked_list);
  sorted_insert(&linked_list, 2, -2);
  show(&linked_list);

  clear(&linked_list);

  sorted_insert(&linked_list, 99, 199);
  sorted_insert(&linked_list, 32, -32);
  sorted_insert(&linked_list, 1000, 10);
  sorted_insert(&linked_list, 2, 22);
  sorted_insert(&linked_list, 50, 0);
  sorted_insert(&linked_list, 23, 100);
  sorted_insert(&linked_list, 490, 99);
  show(&linked_list);

  clear(&linked_list);

  return 0;
}

/**
 *
 */
node_t *alloc_node(int key, int value)
{
  node_t *new_node;
  /* alloc memory in heap */
  new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node != NULL) {
    /* set new value */
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
  }
  return new_node;
}

/**
 * リンクリストの一番最後に追加
 */
int push_back(linked_list_t *linked_list, int key, int value)
{
  node_t *node;
  node_t *new_node;
  new_node = alloc_node(key, value);
  if (new_node == NULL) {
    return 0;
  }

  if (linked_list->front == NULL) {
    /* add first node */
    linked_list->front = new_node;
  }
  else {
    /* search last node */
    node = linked_list->front;
    while (node->next != NULL) {
      node = node->next;
    }
    node->next = new_node;
  }

  return 1;
}

/**
 * リンクリストの一番先頭に追加
 */
int push_front(linked_list_t *linked_list, int key, int value)
{
  node_t *new_node;
  new_node = alloc_node(key, value);
  if (new_node == NULL) {
    return 0;
  }

  /* 最初の場所は linked_list->front に登録されているので付け替えるだけ */
  new_node->next = linked_list->front;
  linked_list->front = new_node;

  return 1;
}

/**
 * リンクリストの一番後ろを削除
 */
void pop_back(linked_list_t *linked_list)
{
  node_t *node;
  node_t *prev;

  if (linked_list->front == NULL) {
    /* 何もない場合は何もしない */
    return;
  }

  /* 一番最後とその一つ手前のノードを探す */
  node = linked_list->front;
  prev = node;
  while (node->next != NULL) {
    prev = node;
    node = node->next;
  }

  if (prev == node) {
    /* prev == node なので一つしかnodeがなかった */
    linked_list->front = NULL;
    free(node);
  }
  else {
    free(node);
    prev->next = NULL;
  }
}

/**
 * リンクリストの一番先頭を削除
 */
void pop_front(linked_list_t *linked_list)
{
  node_t *node;

  node = linked_list->front;
  if (node != NULL) {
    linked_list->front = node->next;
    free(node);
  }
}

/**
 * リンクリストに、keyでソートされた位置（昇順）に追加
 */
int sorted_insert(linked_list_t *linked_list, int key, int value)
{
  node_t *new_node;
  node_t *node;
  node_t *prev;

  new_node = alloc_node(key, value);
  if (new_node == NULL) {
    return 0;
  }

  node = linked_list->front;
  prev = linked_list->front;
  while (node != NULL) {
    if (node->key >= new_node->key) {
      break;
    }
    prev = node;
    node = node->next;
  }

  if (prev == node) {
    new_node->next = node;
    linked_list->front = new_node;
  }
  else {
    prev->next = new_node;
    new_node->next = node;
  }
}

/**
 * リンクリストのすべての要素を出力
 */
void show(const linked_list_t *linked_list)
{
  node_t *node = linked_list->front;
  while (node != NULL) {
    printf("key=%d, value=%d\n", node->key, node->value);
    node = node->next;
  }
  printf("==========\n");
}

/**
 * リンクリストの要素をすべて解放
 */
void clear(linked_list_t *linked_list)
{
  node_t *node;
  node_t *next;
  node = linked_list->front;
  linked_list->front = NULL;

  while (node != NULL) {
    next = node->next;
    free(node);
    node = next;
  }
}

/* vim: se nu ts=2 sw=2 si et : */
