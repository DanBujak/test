#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "qs_config.h"

#define ARR_N 20

/*
 * Function to print array 
 */
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


/*
 * Function to swap two elements of an array 
 */
void swap_array ( int * a, int idxL, int idxR )
{
  int tempVal = a[idxL];
  a[idxL] = a[idxR];
  a[idxR] = tempVal;
}


/*
 * Partition function
 */
int parition_array ( int * a, int idxL, int idxR )
{
  int pivot = a[idxR];
  
  int low = idxL;
  int high = idxR - 1;

  while ( low <= high )
  {
    while ( a[low] < pivot ) { low++; }
    while ( a[high] > pivot ) { high--; }

    /* Values at index L & R should be swapped */
    if ( low <= high )
    {
      printf("Swap: [%d]<->[%d]\r\n", low, high);
      swap_array( a, low, high );
      low++;
      high--;
    }
  }

  /* Swap pivot with Left to final position */
  printf("Swap: [%d]<->[%d]\r\n", low, idxR);
  swap_array(a, low, idxR );
  return low;
}

/*
 * Recursive qsort function
 */
void quicksort_rec ( int * a, int idxL, int idxR )
{
  /* Sort complete */
  if (idxL >= idxR )
  {
    return;
  }

  printf("\r\nQuicksort (%d, %d)\r\n", idxL, idxR);
  int partition = parition_array( a, idxL, idxR );
  printf("Partition Index = %d\r\n", partition);
  quicksort (a, idxL, partition - 1 );
  quicksort (a, partition + 1, idxR );
}



/*
 * Iterative qsort function
 */
void quicksort_iterative ( int * a, int idxL, int idxR )
{

}


/*
 * Compare function for qsort
 */
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


/** Main application entry */
int main ( void )
{
  printf("Quicksort Demo Version %d.%d\r\n", QuickSort_VERSION_MAJOR, QuickSort_VERSION_MINOR);

  int array[ARR_N] = { 90, 30, 53, 27, 97, 15, 81, 27, 78, 81, 41, 54, 69, 24, 95, 78, 61, 52, 88, 70 };

  //qsort((void*)array, ARR_N, sizeof(int), cmpfunc);
  //print_array(array, ARR_N);
  

  srand(time(NULL));

  printf("\r\n1. Generate an array\r\n");
  for ( int i = 0; i < ARR_N; i++ )
  {
    array[i] = rand() % 100;   
  }
  print_array(array, ARR_N);

  printf("\r\n2. Quicksort Array (n=%d)\r\n", ARR_N);
  quicksort(array, 0, ARR_N - 1);

  printf("Result = \r\n");
  print_array(array, ARR_N);

  return 0;
}