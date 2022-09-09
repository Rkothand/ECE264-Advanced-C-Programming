#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap1(int * a, int * b)
{
  int * t = a;
  a = b;
  b = t;
}

void swap2(int a, int b)
{
  int t = a;
  a = b;
  b = t;
}

void swap3(int * a, int * b)
{
  int t = * a;
  * a = * b;
  * b = t;
}

void swap4(int * a, int * b)
{
  int t = * a;
  a = b;
  * b = t;
}

int main(int argc, char * argv[])
{
  int s = 2020;
  int t = 264;
  swap1(& s, & t);
  printf("swap1: s = %d, t = %d\n", s, t);

  s = 2020;
  t = 264;
  swap2(s, t);
  printf("swap2: s = %d, t = %d\n", s, t);

  s = 2020;
  t = 264;
  swap3(& s, & t);
  printf("swap3: s = %d, t = %d\n", s, t);

  s = 2020;
  t = 264;
  swap4(& s, & t);
  printf("swap4: s = %d, t = %d\n", s, t);

  return EXIT_SUCCESS;
}
