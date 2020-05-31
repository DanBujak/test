#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "qs_config.h"

#define ARR_N 20

void print_array ( int * pArray, int len )
{
  printf("Array Contents:\r\n\t");

  for ( int i = 0; i < len; i++ )
  {
    printf("%2d, ", i);
  }
  printf("\r\n\t");
  for ( int i = 0; i < len; i++ )
  {
    printf("%02d, ", pArray[i]);
  }
  printf("\r\n");
}

void swap_array ( int * a, int idxL, int idxR )
{
  printf("Swapping %d & %d\r\n", idxL, idxR );
  int tempVal = a[idxL];
  a[idxL] = a[idxR];
  a[idxR] = tempVal;
  print_array(a, ARR_N);
}

void parition_array ( int * a, int len )
{
}

void quicksort_array ( int * a, int lenArray )
{
  int pivot;

  int idxPivot = lenArray -1;
  int idxLeft  = 0;
  int idxRight = lenArray - 2;

  
  //for ( int i = 0; i < lenArray; i++ )

  pivot = a[idxPivot];
  printf("Pivot = %d\r\n", pivot);
  while ( idxLeft < idxRight )
  {
    printf("Left(%d) = %d, Right(%d) = %d, Pivot(%d) = %d\r\n", idxLeft, a[idxLeft], idxRight, a[idxRight], idxPivot, a[idxPivot]);
    /* Swap condition */
    if ( ( a[idxLeft] > pivot ) && ( a[idxRight] < pivot ) )
    {
      swap_array(a, idxLeft, idxRight);
      idxLeft++;
      idxRight--;
    }
    
    /* No swap possible, walk indeces */
    else
    {
      if ( a[idxLeft] < pivot )
      {
        idxLeft++;
      }
  
      if ( a[idxRight] > pivot )
      {
        idxRight--;
      }
    }
  }
  printf("Swap Pivot and idxLeft\r\n");
  swap_array(a, idxLeft, idxPivot);
}


/** Main application entry */
int main ( void )
{
  printf("Quicksort Demo Version %d.%d\r\n", QuickSort_VERSION_MAJOR, QuickSort_VERSION_MINOR);

  int array[ARR_N] = { 90, 30, 53, 27, 97, 15, 81, 27, 78, 81, 41, 54, 69, 24, 95, 78, 61, 52, 88, 70 };

  srand(time(NULL));

  printf("\r\n1. Generate an array\r\n");
  for ( int i = 0; i < ARR_N; i++ )
  {
    //array[i] = rand() % 100;   
  }
  print_array(array, ARR_N);

  printf("\r\n2. Quicksort Array (n=%d)\r\n", ARR_N);
  quicksort_array(array, ARR_N);

  printf("Result = \r\n");
  print_array(array, ARR_N);

  return 0;
}