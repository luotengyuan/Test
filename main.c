#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct monkey{
    int age;
    int master;
    int code;
}monkey;

void TraverseCallback(void *param)
{
    monkey *thismonkey=(monkey*)param;
    int sum=thismonkey->age+thismonkey->master+thismonkey->code;
    printf("%d,%d,%d,SUM:%d\n",thismonkey->age,thismonkey->master,thismonkey->code,sum);
}

void SortCallback(void *pp1, void *pp2, void *pp3)
{
    //if(prev == NULL){
//        NodePtr thisNode = (NodePtr)this;
//        NodePtr nextNode = (NodePtr)next;
//        
//        monkey *thisMonkey=(monkey*)thisNode->value;
//        monkey *nextMonkey=(monkey*)nextNode->value;
//        
//        printf("thisage=%d,nextage=%d\n",thisMonkey->age,nextMonkey->age);
//        if(thisMonkey->age > nextMonkey->age)
//        {
//            thisNode->next = nextNode->next;
//            (*l).head = nextNode;
//            nextNode->next = thisNode;
//        }
//    } else {
//        NodePtr prevNode = (NodePtr)prev;
//        NodePtr thisNode = (NodePtr)this;
//        NodePtr nextNode = (NodePtr)next;
//        
//        monkey *thisMonkey=(monkey*)thisNode->value;
//        monkey *nextMonkey=(monkey*)nextNode->value;
//        printf("thisage=%d,nextage=%d\n",thisMonkey->age,nextMonkey->age);
//        if(thisMonkey->age > nextMonkey->age)
//        {
//            thisNode->next = nextNode->next;
//            prevNode->next = nextNode;
//            nextNode->next = thisNode;
//        }
//    }
        NodePtr p1 = (NodePtr)pp1;
        NodePtr p2 = (NodePtr)pp2;
        NodePtr p3 = (NodePtr)pp3;
        
        monkey *m1=(monkey*)p1->value;
        monkey *m2=(monkey*)p2->value;
        printf("thisage=%d,nextage=%d\n",m1->age,m2->age);
        
              if ((m1->age)>(m2->age)) {//避免在双层循环内进行特殊情况的判断，因为这里的时间复杂度是O(n^2)                
                  p1->next=p2->next;                
                  p2->next=p1;                
                  p3->next=p2;                
                  p3=p2; //由于加了表头和表尾，整个交换过程更简洁                
                  p2=p1->next;            
              } else {                
                  p3=p1;                
                  p1=p2;                
                  p2=p2->next;            
              }   
}

int main(int argc ,char *argv[])
{
    LIST animals;
    monkey lucy;
    monkey jack;
    monkey rose;
    monkey tom;
    monkey lili;
    monkey *p;
    ListInit(&animals);
    
    
    lucy.age=44;
    lucy.master=23;
    lucy.code=23;
    
    jack.age=6;
    jack.master=22;
    jack.code=22;

    rose.age=7;
    rose.master=23;
    rose.code=23;

    tom.age=23;
    tom.master=24;
    tom.code=24;
    
    lili.age=5454;
    lili.master=25;
    lili.code=25;
    
    ListInsert(&animals,&lucy);
    ListInsert(&animals,&jack);
    ListInsert(&animals,&rose);
    ListInsert(&animals,&tom);
    ListInsert(&animals,&lili);
    
    ListTraverse(&animals,TraverseCallback);

    system("pause");
    //ListRemove(&animals,&tom);
    
    ListSort(&animals,SortCallback);
    
    system("pause");
    ListTraverse(&animals,TraverseCallback);

    printf("%d\n",ListLength(&animals));

    system("pause");
    return EXIT_SUCCESS;
}
