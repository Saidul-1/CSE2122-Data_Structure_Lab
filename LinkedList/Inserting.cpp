/* Md. Saidul Islam 2110776106 */
/* insert an element in a sorted linked list and another element at a specific position*/
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
    string elements[]={"Bilal", "Delowar", "Fahim", "Hamim", "Saidul"};
    nodeptr start, curr, newPtr;
    // create the linked list and add the elements from the array
    start=curr=NULL;
    for(int i=0;i<5;i++){
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
nodeptr insert(nodeptr start, string element){ // insert in a sorted linked list
    nodeptr curr, newEl;
    newEl = newNode(element);
    if(start->info>=element){
        newEl->next=start; 
        return newEl;
    }
    for(curr=start; curr->next!=NULL && (curr->next->info)<element; curr=curr->next);
    newEl->next=curr->next;
    curr->next=newEl;
    return start;
}
nodeptr insertAt(nodeptr start, string element, int pos){ // insert at a position
    int i;
    nodeptr curr, newEl;
    curr=start;
    newEl = newNode(element);
    if(pos==1){
        newEl->next=start; 
        cout<<"After inserting the new element at position "<<pos<<":\n";
        print(newEl);
        return newEl;
    }
    for(i=2;curr!=NULL;i++){
        if(i==pos){
            newEl->next=curr->next;
            curr->next=newEl;
            cout<<"After inserting the new element at position "<<pos<<":\n";
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
    cout<<"Before inserting new name:\n";
    print(names);
    names = insert(names, "Nayeem");// insert an element in a sorted linked list
    cout<<"After inserting the new element:\n";
    print(names);
    names = insertAt(names, "Abdullah", 1);// insert an element at a position
    return 0;
}
