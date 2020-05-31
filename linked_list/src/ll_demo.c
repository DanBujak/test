#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#include "ll_config.h"
#include "linkedlist.h"


int test_1 ( void )
{

}


/** Main application entry */
int main ( void )
{
  printf("Linked List Demo Version %d.%d\r\n", LinkedList_VERSION_MAJOR, LinkedList_VERSION_MINOR);

  struct nData data;
  struct Node * my_LL = NULL;

  printf("\r\n0. Node is pointing to %p\r\n", (uint32_t *)my_LL);
  
  LL_Print(my_LL);


  struct Node * tempNode;

  /* */
  printf("\r\n1. Push data to LL [0,2,3]\r\n");
  
  data.x = 0;
  LL_Insert_Head(&my_LL, &data);
  data.x = 2;
  LL_Insert_Head(&my_LL, &data);
  data.x = 3;
  LL_Insert_Head(&my_LL, &data);
  LL_Print(my_LL);

  printf("\r\n2. Forgot to add 1\r\n");
  data.x = 2;
  tempNode = LL_Get_Node_By_Key(my_LL, &data);
  if ( tempNode == NULL )
  {
    printf("Error: Unable to find Node 2\r\n");
    return -1;
  }
  data.x = 1;
  LL_Insert_Behind(tempNode, &data );
  LL_Print(my_LL);

  printf("\r\n3. Pop off head\r\n");
  LL_Pop_Head(&my_LL, &data);
  printf("\tResult = %d\r\n", data.x );
  LL_Print(my_LL);

  printf("\r\n4. Add -1 to the back\r\n");
  data.x = -1;
  LL_Insert_Tail(&my_LL, &data);
  LL_Print(my_LL);

  printf("\r\n5. Insert 33@3, 22@2, 0@0, 100@10\r\n");
  data.x = 33;
  LL_Insert_At(&my_LL, 3, &data);
  LL_Print(my_LL);

  data.x = 22;
  LL_Insert_At(&my_LL, 2, &data);
  LL_Print(my_LL);

  data.x = 0;
  LL_Insert_At(&my_LL, 0, &data);
  LL_Print(my_LL);

  data.x = 100;
  LL_Insert_At(&my_LL, 10, &data);
  LL_Print(my_LL);


  printf("\r\n6. Get value at index 3 & 2\r\n");
  LL_Get_At(my_LL, 3, &data);
  printf("\tResult = %d\r\n", data.x );
  LL_Get_At(my_LL, 2, &data);
  printf("\tResult = %d\r\n", data.x );

  printf("\r\n7. Delete node containing 33, and node containing 2\r\n");
  data.x = 33;
  tempNode = LL_Get_Node_By_Key(my_LL, &data);
  LL_Delete_Node(&my_LL, tempNode);
  LL_Print(my_LL);

  data.x = 2;
  tempNode = LL_Get_Node_By_Key(my_LL, &data);
  LL_Delete_Node(&my_LL, tempNode);
  LL_Print(my_LL);

  printf("\r\n7. Reverse the LL\r\n");
  LL_Reverse(&my_LL);
  LL_Print(my_LL);

  printf("\r\n8. Adding some random items to head\r\n");
  srand(time(NULL));
  #define RANDOM_RANGE   (100)
  #define RANDOM_MIN     (-50)
  for ( uint8_t i = 0; i < 20; i++ )
  {
    data.x = rand() % RANDOM_RANGE + RANDOM_MIN;
    LL_Insert_Head(&my_LL, &data);
  }
  LL_Print(my_LL);

  printf("\r\n9. Sort the list\r\n");
  LL_BubbleSort(&my_LL);
  LL_Print(my_LL);
  
  printf("\r\nX. Destroy List\r\n");
  int cnt = LL_Destroy(my_LL);
  printf("Destroyed %d items\r\n", cnt);


  return 0;
}