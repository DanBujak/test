/**
 * @file linkedlist.h
 */


/** Data to hold in our LL */
struct nData {
  int x;
};

/** Linked List Node */
struct Node {
  struct nData  data;             /** Node data */
  struct Node * next;      /** Node next element */
};

/* Queue API */
int           LL_Create           ( struct Node ** head_ref );
int           LL_Destroy          ( struct Node * head_ref );
void          LL_Print            ( struct Node * node );
int           LL_Insert_Head      ( struct Node ** head_ref, struct nData * data );
int           LL_Pop_Head         ( struct Node ** head_ref, struct nData * result );
int           LL_Insert_Behind    ( struct Node * prev_ref, struct nData * data );
int           LL_Insert_Tail      ( struct Node ** head_ref, struct nData * data );
int           LL_Insert_At        ( struct Node ** head_ref, uint16_t n, struct nData * data );
struct Node * LL_Get_Node_By_Key  ( struct Node * head_ref, struct nData * value );
int           LL_Get_At           ( struct Node * head_ref, uint16_t n, struct nData * value );
int           LL_Delete_Node      ( struct Node ** head_ref, struct Node * target );
int           LL_Reverse          ( struct Node ** head_ref );
int           LL_BubbleSort       ( struct Node ** head_ref );
int           LL_Bubble           ( struct Node * head_ref );
