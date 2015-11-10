#include <stdio.h>
#include <stdlib.h>

int CMP(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
  int i;
  int arrAy[] = {10, 8, 6, 4, 2, 1};

  qsort(arrAy, 4, sizeof(int), CMP);
  for (i = 0; i < 6; i++) printf("%d\n", arrAy[i]);

  return 0;
}
