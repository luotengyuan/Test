#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <malloc.h>

#ifdef __cplusplus
extern "C"{
#endif

struct LIST;
struct NODE;
struct OPERATIONS;/*·ÏÆú*/

typedef struct NODE{
    unsigned int value;
    struct NODE* next;
}NODE,*NodePtr;

typedef struct OPERATIONS{
    void (*insert)(struct LIST *l , void* p);
    void (*remove)(struct LIST *l , void* p);
    void (*traverse)(struct LIST *l , void (*TraverseCallback)(void*));
}OPERATIONS,*OperaPtr;

typedef struct LIST{
    NodePtr head;
    int length;
}LIST;

void ListInit(struct LIST* l);
void ListInsert(struct LIST *l , void* p);
void ListRemove(struct LIST *l , void* p);
void ListTraverse(struct LIST *l , void(*TraverseCallback)(void*));
void ListSort(struct LIST *l , void(*SortCallback)(void*, void*, void*));
int ListLength(struct LIST *l);

static    NodePtr ListNewNode();

#ifdef __cplusplus
}
#endif

#endif
