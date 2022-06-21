#include <stdio.h>

#define SIZE 10

/**
 *
 */
int main(void)
{
  int values[SIZE];
  int i;

  for (i = 0; i < SIZE; i++) {
    printf("%d個目: ", i + 1);
    scanf("%d", &values[i]);
  }

  printf( "\n偶数：" );
  for (i = 0; i < SIZE; i++) {
    if (( values[i] % 2 ) == 0) {
      printf("%d ", values[i]);
    }
  }

  printf( "\n奇数：" );
  for (i = 0; i < SIZE; i++) {
    if (( values[i] % 2 ) != 0) {
      printf("%d ", values[i]);
    }
  }

  printf("\n");

  return 0;
}

/* vim: se nu ts=2 sw=2 si et : */
