#include <stdio.h>

typedef struct grades {
  int no;                /* 出席番号 */
  unsigned int japanese; /* 国語 */
  unsigned int math;     /* 数学 */
  unsigned int science;  /* 理科 */
  unsigned int social;   /* 社会 */
} grades_t;

void calc_average(const grades_t *data)
{
  grades_t total = { 0 };
  unsigned int count = 0;
  while (data[count].no > 0) {
    total.japanese += data[count].japanese;
    total.math += data[count].math;
    total.science += data[count].science;
    total.social += data[count].social;
    count++;
  }
  printf("国語: %f, 算数: %f, 理科: %f, 社会: %f\n",
    (float)total.japanese / count,
    (float)total.math / count,
    (float)total.science / count,
    (float)total.social / count);
}

int main(void)
{
  grades_t myclass[] = {
    { 1001, 85, 74, 63, 90 },
    { 1002, 78, 65, 70, 62 },
    { 1003, 89, 92, 88, 76 },
    { 1004, 32, 48, 66, 25 },
    { 1005, 92, 76, 81, 98 },
    {   -1,  0,  0,  0,  0 }
  };

  calc_average(myclass);

  return 0;
}

/* vim: se nu ts=2 sw=2 si et : */
