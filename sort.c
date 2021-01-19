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
    p=&h; //ʹ��ͷ��㣬������������Ĵ�����Ϊ����̫��    
    while (p->NEXT!=NULL)    
    {        
        p=p->NEXT;    
    }    
    p=p->NEXT=&t; //�����������β�ڵ���ܱ������������м�ȥ������ʹ����һ���̶��Ľڵ�    
    while (p!=h.NEXT)    {        
          p3=&h;        
          p1=p3->NEXT;        
          p2=p1->NEXT;        
          while (p2!=p) //pָ������Ѿ���Ľڵ�        
          {            
              if ((p1->COE)>(p2->COE)) {//������˫��ѭ���ڽ�������������жϣ���Ϊ�����ʱ�临�Ӷ���O(n^2)                
                  p1->NEXT=p2->NEXT;                
                  p2->NEXT=p1;                
                  p3->NEXT=p2;                
                  p3=p2; //���ڼ��˱�ͷ�ͱ�β�������������̸����                
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
          p=p->NEXT;  //��Ȼ���︴�Ӷ���O(n)������Զ����˫��ѭ���ڵ����⴦��Ҫ��Ч�Ķ�    
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
