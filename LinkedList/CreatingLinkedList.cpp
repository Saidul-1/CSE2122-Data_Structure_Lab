/* Md. Saidul Islam 2110776106 */
/* Create a Linked List and store the value 5, 3, 9, 42, 0, 10 */
#include <bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next = NULL;
};
typedef struct node *nodeptr;

nodeptr newNode(int inf){   //create a new node and return the pointer 
    nodeptr p = (nodeptr)malloc(sizeof(struct node));
    if(p!=NULL){
        p->info=inf;
    }
    return p;
}
int main()
{
    int elements[]={5,3,9,42,0,10};
    nodeptr start, curr, newPtr;
    //create the linked list and add the elements from the array
    start=curr=NULL;
    for(int i=0;i<6;i++){
      newPtr = newNode(elements[i]);
      if(newPtr==NULL){cout<<"Memory Limit Exit\n"; exit(0);}
      else{
         if(start==NULL){
            start=curr=newPtr;
         }
         else{
            curr->next = newPtr;
            curr=newPtr;
         }
      }
    }
    //print the elements of the linked list
    for(curr=start;curr!=NULL;curr=curr->next){
        cout<<(curr->info)<<" ";
    }
    return 0;
}
