#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef exam
int compInt(const void * p1, const void * p2)
{
  int * v1 = (int *) p1;
  int * v2 = (int *) p2;
  if (v1 > v2)  { return 1; }
  if (v1 == v2) { return 0; }
  return -1;
}

int main(int argc, char ** argv)
{
  int arr[10] = {9, 3, 4, 2, 8, 7, 1, 5, 6, 0};
  qsort(arr, 10, sizeof(int), compInt);
 
  int i;
    printf("%d\n",arr[2]);
  printf("%d\n",arr[4]);
  for (i = 0; i < 10; i ++)
    {
      printf("%d ", arr[i]);
    }
  printf("\n");
  return EXIT_SUCCESS;
}
#endif