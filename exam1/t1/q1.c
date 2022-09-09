#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
// tell compiler not to pad any space between
// attributes in structure

// assume the size of the data types
// char:    1 byte
// int:     4 bytes
// double:  8 bytes
// pointer: 8 bytes

#define NUMVECTOR 10
typedef struct
{
  int x;
  int y;
  int z;
} Vector;

int main(int argc, char ** argv)
{
  Vector varr[NUMVECTOR];
  printf("%ld\n", sizeof(varr)); // <- Answer A: the output?
  Vector * vptr;
  vptr = & varr[0];
  printf("%ld\n", sizeof(vptr)); // <- Answer B: the output?
  // Hint: think carefully about the difference of A and B
  // initialize the attributes
  int ind;
  for (ind = 0; ind < NUMVECTOR; ind ++)
    {
      varr[ind].x = ind;
      varr[ind].y = ind * 2;
      varr[ind].z = ind * 3;
    }
  int * iptr = & (varr[3].z);
  for (ind = 0; ind < 4; ind ++)
    {
      iptr[ind] = ind;
    }

  for (ind = 3; ind < 5; ind ++)
    {
      printf("%d\n", varr[ind].x + varr[ind].y + varr[ind].z);
      // <- Answer C, D for ind = 3, 4
    }
  return EXIT_SUCCESS;
}

