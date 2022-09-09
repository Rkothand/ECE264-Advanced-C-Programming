// ***
// *** You must modify this file
// ***
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_COUNTVECTOR
int countVector(char *filename)
{
  FILE *fptr = fopen(filename, "rb");
  Vector buffer;

  if (fptr == NULL)
  {
    return -1;
  }
  else
  {
    int count = 0;
    while (!feof(fptr))
    {
      int rsize = fread(&buffer, sizeof(Vector), 1, fptr);
      if (rsize == 1)
        count++;
    }
    // printf("count is %d \n", count);
    fclose(fptr);
    return count;
  }
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", )
  //
  // If fopen fails, return -1
  //
  //
  // For the mode of fopen, you may use "r" without b
  //
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char *filename, Vector *vecArr, int size)
{
  FILE *fptr = fopen(filename, "rb");
  Vector buffer;

  if (fptr == NULL)
  {
    return false;
  }

  else
  {

    int count = 0;
    while (!feof(fptr))
    {
      int rcount = fread(&buffer, sizeof(Vector), 1, fptr);
      if (rcount == 1)
      {
        memcpy(&vecArr[count], &buffer, sizeof(Vector));
        count++;
      }
    }
    fclose(fptr);
    if (count != size)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
  // if fopen fails, return false
  // read Vectors from the file.
  //
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  //
  // if everything is fine, fclose and return true
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  Vector *f1 = (Vector *)p1;
  Vector *f2 = (Vector *)p2;
  if (f1->x < f2->x)
    return -1;
  if (f1->x > f2->x)
    return 1;
  if (f1->x == f2->x)
  {
    if (f1->y < f2->y)
      return -1;
    if (f1->y > f2->y)
      return 1;

    if (f1->y == f2->y)
    {
      if (f1->z < f2->z)
        return -1;
      if (f1->z > f2->z)
        return 1;
    }
  }

  return 0;

  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  // If the first vector's x is greater than the second vector's x
  // return 1
  // If the two vectors' x is the same, compare the y attribute
  //
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  //
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char *filename, Vector *vecArr, int size)
{

  FILE *fptr = fopen(filename, "wb");

  if (fptr == NULL)
  {
    return false;
  }

  else
  {

    int count = 0;
    int wcount = 0;

    while (count < size)
    {
      int s = fwrite(&vecArr[count], sizeof(Vector), 1, fptr);
      if (s == 1)
      {
        wcount++;
      }
      count++;
    }
    fclose(fptr);
    
    //printf("wcount %d and size is %d",wcount,size);
    if (wcount != size)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
  // if fopen fails, return false
  // write the array to file using fwrite
  // need to check how many have been written
  // if not all are written, fclose and return false
  //
  // fclose and return true
}
#endif

// This function is provided to you. No need to change
void printVector(Vector *vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind++)
  {
    printf("%6d %6d %6d\n",
           vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
  }
}
