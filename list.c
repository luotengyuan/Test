#include "list.h"

static OPERATIONS ops={    ListInsert,
    ListRemove,
    ListTraverse,
};

void ListInit(LIST* l)
{
    (*l).head=NULL;
    (*l).length=0;
}

void ListInsert(LIST *l , void *thisnode)
{
    NodePtr p=ListNewNode();
    p->value=(unsigned int)thisnode;
    p->next=(*l).head;
    (*l).head=p;
    (*l).length+=1;
}

void ListRemove(LIST *l , void *thisnode)
{
    NodePtr head;
    NodePtr prev;
    prev=(*l).head;
    if(prev==NULL){
        printf("This list is NULL\n");
        return ;
    }
    if(thisnode==NULL){
        printf("this node is NULL\n");
        return ;
    }
    if(prev->value==(unsigned int)thisnode){
        (*l).head=(*l).head->next;
        free(prev);
        (*l).length-=1;
    }else{
        for(head=(*l).head ; head!=NULL ; head=head->next){
            if((unsigned int)thisnode==head->value){
                prev->next=head->next;
                free(head);
                (*l).length-=1;
                break;
            }
            prev=head;
        }
        if(head==NULL){
            printf("This list has no this node\n");
        }
    }
}

NodePtr ListNewNode()
{
    return (NodePtr)malloc(sizeof(NODE));
}
/************************************************************************/
/* if you wanna do something to the node, please write a callback. it   */
/* must has the type of void(*TraverseCallback)(void*)                  */
/************************************************************************/
void ListTraverse(LIST *l , void(*TraverseCallback)(void*))
{
    NodePtr head=(*l).head;
    for( ; head!=NULL ; head=head->next)
        TraverseCallback((void*)(head->value));
    printf("--------------\n");
}

/************************************************************************/
/* if you wanna do something to the node, please write a callback. it   */
/* must has the type of void(*SortCallback)(void*)                      */
/************************************************************************/
void ListSort(LIST *l , void(*SortCallback)(void*, void*, void*))
{
//    int length = (*l).length;
//    int i = 0;
//    int start = length;
//    NodePtr headNode = NULL;
//    NodePtr listNode = NULL;
//    if(length >= 2){
//        for( ; i <= length ; i++)
//        {
//             int j = 0;
//             printf("i=%d\n",i);
//             NodePtr prevNode=NULL;
//             NodePtr thisNode=(*l).head;
//             NodePtr nextNode = thisNode->next;
//             for( ; nextNode!=NULL; prevNode=thisNode, thisNode=nextNode, nextNode = nextNode->next, j++)
//             {
//                  if(j <= start)
//                  {
//                      printf("j=%d\n",j);
//                      if(j==0){
//                          SortCallback(l, NULL, (void*)(thisNode), (void*)(nextNode));
//                      } else {
//                          SortCallback(l, (void*)(prevNode), (void*)(thisNode), (void*)(nextNode));
//                      }
//                  }
//             }
//             listNode = thisNode;
//             listNode->next = headNode;
//             headNode = listNode;
//             start--;
//        }
//    }
//    (*l).head = headNode;
    NodePtr head = (*l).head;
    NodePtr p,p1,p2,p3;    
    NODE h, t;    
    if (head == NULL) 
       return;   
    h.next=head;    
    p=&h; //使用头结点，避免特殊情况的处理，因为代价太高    
    while (p->next!=NULL)    
    {        
        p=p->next;    
    }    
    p=p->next=&t; //！！！链表的尾节点可能被交换到链表中间去，这里使用了一个固定的节点    
    while (p!=h.next)    {        
          p3=&h;        
          p1=p3->next;        
          p2=p1->next;        
          while (p2!=p) //p指向的是已就序的节点        
          {            
              SortCallback((void*)(p1), (void*)(p2), (void*)(p3));     
          }        
          p=p1;    
    }    
    while (p->next!=&t)    {        
          p=p->next;  //虽然这里复杂度是O(n)，但是远比在双层循环内的特殊处理要高效的多    
    }    
    p->next=NULL;    
    (*l).head = h.next;
}

int ListLength(LIST *l)
{
    return (*l).length;
}
