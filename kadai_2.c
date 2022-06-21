#include <stdio.h>

#define SIZE 10


/**
 *
 */
int average(int x, int y)
{
  return ((x + y) / 2);
}

/**
 *
 */
int main(void)
{
  int x, y;
  int result;

  while (1) {
    printf("1つ目: ");
    scanf("%d", &x);
    printf("2つ目: ");
    scanf("%d", &y);

    result = average(x, y);
    printf("平均: %d\n", result);
    printf("\n");
  }

  return 0;
}

/* vim: se nu ts=2 sw=2 si et : */
