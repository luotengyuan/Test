#include <stdio.h>
#define FMT struct MUL
struct MUL {    
       int COE;    
       int EXP;    
       FMT *NEXT;
};
FMT *sort(FMT *head){    
    FMT *p,*p1,*p2,*p3;    
    FMT h, t;    
    if (head == NULL) 
       return NULL;   
    h.NEXT=head;    
    p=&h; //使用头结点，避免特殊情况的处理，因为代价太高    
    while (p->NEXT!=NULL)    
    {        
        p=p->NEXT;    
    }    
    p=p->NEXT=&t; //！！！链表的尾节点可能被交换到链表中间去，这里使用了一个固定的节点    
    while (p!=h.NEXT)    {        
          p3=&h;        
          p1=p3->NEXT;        
          p2=p1->NEXT;        
          while (p2!=p) //p指向的是已就序的节点        
          {            
              if ((p1->COE)>(p2->COE)) {//避免在双层循环内进行特殊情况的判断，因为这里的时间复杂度是O(n^2)                
                  p1->NEXT=p2->NEXT;                
                  p2->NEXT=p1;                
                  p3->NEXT=p2;                
                  p3=p2; //由于加了表头和表尾，整个交换过程更简洁                
                  p2=p1->NEXT;            
              } else {                
                  p3=p1;                
                  p1=p2;                
                  p2=p2->NEXT;            
              }        
          }        
          p=p1;    
    }    
    while (p->NEXT!=&t)    {        
          p=p->NEXT;  //虽然这里复杂度是O(n)，但是远比在双层循环内的特殊处理要高效的多    
    }    
    p->NEXT=NULL;    
    return h.NEXT;
}
int main() {    
    FMT h,j,k,l;    
    h.NEXT=&j;    
    h.COE=65;    
    j.NEXT=&k;    
    j.COE=445;    
    k.NEXT=&l;    
    k.COE=68;    
    l.NEXT=NULL;    
    l.COE=543;    
    FMT* p = sort(&h);    
    while (p != NULL) {        
          printf("%d ", p->COE);        
          p=p->NEXT;    
    }    
    system("pause");
    return 0;
}
