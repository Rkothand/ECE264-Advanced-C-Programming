// ***
// *** You must modify this file
// ***
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char *msg, int *arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind++)
  {
    printf("%d\n", arr[ind]);
  }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char *filename, int **arr, int *size)
{

  // use fopen to open the file for read
  // return false if fopen fails
  FILE *fptr = fopen(filename, "rb");
  if (fptr == NULL)
  {
    return false;
  }
  else
  {

    // use fseek to go to the end of the file
    // check whether fseek fails
    // if fseek fails, fclose and return false

    if (fseek(fptr, 0, SEEK_END) != 0)
    {
      return false;
    }
    // use ftell to determine the size of the file
    int lsize = ftell(fptr);

    // use fseek to go back to the beginning of the file
    // check whether fseek fails
    // if fseek fails, fclose and return false
    if (fseek(fptr, 0, SEEK_SET) != 0)
    {
      fclose(fptr);
      return false;
    }

    // the number of integers is the file's size divided by
    // size of int
    int num_int = lsize / sizeof(int);

    // allocate memory for the array
    // if malloc fails, fclose and return false
    int *ptrArr = malloc(sizeof(int) * num_int);
    if (ptrArr == NULL)
    {
      fclose(fptr);
      return false;
    }
    // use fread to read the number of integers in the file
    int buffer;
    int count = 0;
    while (!feof(fptr))
    {
      int icount = fread(&buffer, sizeof(int), 1, fptr);
      if (icount == 1)
      {
        ptrArr[count++] = buffer;
      }
    }

    // if fread does not read the correct number
    // release allocated memory
    // fclose
    // return false
    if (count != num_int)
    {
      free(ptrArr);
      fclose(fptr);
      return false;
    }

    // if fread succeeds
    // close the file
    fclose(fptr);

    // update the argument for the array address
    *arr = ptrArr;

    // update the size of the array
    *size = num_int;
  }

  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char *filename, const int *arr, int size)
{
  // fopen for write
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
      int s = fwrite(&arr[count], sizeof(int), 1, fptr);
      if (s == 1)
      {
        wcount++;
      }
      count++;
    }
    fclose(fptr);
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

  // use fwrite to write the entire array to a file

  // check whether all elements of the array have been written

  // fclose

  // if not all elements have been written, return false

  // if all elements have been written, return true
}
#endif

#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int *arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading.
  printInput("Merge in", arr, l, m, r);
#endif

  int ar1Size = m - l + 1;
  int ar2Size = r - m;
  // if one or both of the arrays are empty, do nothing

  if (ar1Size == 0 || ar2Size == 0)
    return;

  int *left = malloc(sizeof(int) * ar1Size);
  int *right = malloc(sizeof(int) * ar2Size);

  for (int i = 0; i < ar1Size; i++)
    left[i] = arr[l + i];
  for (int j = 0; j < ar2Size; j++)
    right[j] = arr[m + 1 + j];

  int i = 0;
  int j = 0;
  int k = l;

  while (i < ar1Size && j < ar2Size)
  {
    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < ar1Size)
  {
    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < ar2Size)
  {
    arr[k] = right[j];
    j++;
    k++;
  }
  //printf("sorting %d to %d with m as %d", l, r, m);
  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write

  // merge the two parts (each part is already sorted) of the array
  // into one sorted array

  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading.
  //printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r)
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading.
  printInput("mergeSort", arr, l, r, -1);
#endif

  if (r - l <= 0)
    return;

  // if the array has no or one element, do nothing

  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);
}
// divide the array into two arrays
// call mergeSort with each array
// merge the two arrays into one

#endif
