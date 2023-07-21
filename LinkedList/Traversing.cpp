/* Md. Saidul Islam 2110776106 */
/* Create a Linked List with the values: 5, 3, 9, 42, 0, 10 and find the minimum, maximum, average and sum */
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
void traverse(nodeptr start){
    nodeptr curr,newPtr;
    int i,mx=-INT_MAX,mn=INT_MAX,sum=0;
    double avg;
    curr=start;
    // Traverse the linked list and find the maximum,minimum,total and average values
    for(i=0;curr!=NULL;i++){
      sum+=curr->info;
      mx=max(mx,curr->info);
      mn=min(mn,curr->info);
      curr=curr->next;
    }
    avg=(double)sum/i;
    cout<<"Maximum value: "<<mx<<"\n";
    cout<<"Minimum value: "<<mn<<"\n";
    cout<<"Total value: "<<sum<<"\n";
    cout<<"Average value: "<<avg<<"\n";
}
int main()
{
    int elements[]={5,3,9,42,0,10};
    nodeptr start, curr, newPtr;
    // create the linked list and add the elements from the array
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
    traverse(start);
    return 0;
}
