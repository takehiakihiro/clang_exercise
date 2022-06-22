#include <stdio.h>
#include <stdint.h>

struct memory_alignment {
  uint32_t first;
  uint16_t second;
  uint32_t third;
  uint8_t fourth;
  uint32_t fifth;
}

int main(void)
{
  struct memory_alignment ma;

  printf("first  address %p\n", &ma.first);
  printf("second address %p\n", &ma.second);
  printf("third  address %p\n", &ma.third);
  printf("fourth address %p\n", &ma.fourth);
  printf("fifth  address %p\n", &ma.fifth);

  return 0;
}

/* vim: se nu ts=2 sw=2 si et : */
