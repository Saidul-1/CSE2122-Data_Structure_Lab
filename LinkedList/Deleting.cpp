/* Md. Saidul Islam 2110776106 */
/* delete an element from a sorted linked list and another element from a specific position*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    string info;
    struct node *next = NULL;
};
typedef struct node *nodeptr;

nodeptr newNode(string inf){   //create a new node and return the pointer 
    nodeptr p = (nodeptr)malloc(sizeof(struct node));
    if(p!=NULL){
        p->info=inf;
    }
    return p;
}

nodeptr create(){
    string elements[]={"Abdullah", "Bilal", "Delowar", "Fahim", "Hamim", "Nayeem", "Saidul"};
    nodeptr start, curr, newPtr;
    // create the linked list and add the elements from the array
    start=curr=NULL;
    for(int i=0;i<7;i++){
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
    return start;
}
void print(nodeptr start){
    for(nodeptr curr=start; curr!=NULL ; curr=curr->next){
        cout<<(curr->info)<<" ";
    }
    cout<<"\n";
}
nodeptr delet(nodeptr start, string element){ // delete an element from a sorted linked list
    nodeptr curr, newEl;
    if(start->info==element){
        start=start->next; 
        return start;
    }
    for(curr=start; curr->next!=NULL && (curr->next->info)<element; curr=curr->next);
    if(curr->next->info!=element){
        cout<<"The element not found!\n"; 
        return start;
    }
    curr->next=curr->next->next;
    return start;
}
nodeptr deleteAt(nodeptr start, int pos){ // delete an element from a position
    int i;
    nodeptr curr, newEl;
    curr=start;
    if(pos==1){
        start=start->next; 
        cout<<"After deleting the element at position "<<pos<<":\n";
        print(start);
        return start;
    }
    for(i=2;curr->next!=NULL;i++){
        if(i==pos){
            curr->next=curr->next->next;
            cout<<"After deleting the element at position "<<pos<<":\n";
            print(start);
            return start;
        }
        curr=curr->next;
    }
    cout<<"The position should be less than "<<i<<"\n";
    return start;
}

int main()
{
    nodeptr names = create();
    cout<<"Before deleting element:\n";
    print(names);
    names = delet(names, "Hamim");// delete a element from a sorted linked list
    cout<<"After deleting the element:\n";
    print(names);
    names = deleteAt(names, 4);// delete an element from a position
    return 0;
}
