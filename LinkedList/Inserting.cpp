/* Md. Saidul Islam 2110776106 */
/* insert an element in a sorted linked list and another element at a specific position*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next;
};
typedef struct node *nodeptr;

nodeptr newNode(int inf){   //create a new node and return the pointer 
    nodeptr p = (nodeptr)malloc(sizeof(struct node));
    if(p != NULL){
        p->info = inf;
        p->next = NULL;
    }
    return p;
}
void print(nodeptr start){
    for(nodeptr curr = start; curr != NULL ; curr = curr->next){
        cout<<(curr->info)<<" ";
    }
    cout<<"\n";
}
nodeptr createLinkedlist(){
	int elements[] = {0, 3, 5, 9, 15, 42};
    nodeptr start, curr, newPtr;
    //create the linked list and add the elements from the array
    start = curr = NULL;
    for(int i=0; i<6 ;i++){
      	newPtr = newNode(elements[i]);
      	if(newPtr == NULL){
      		cout<<"Memory Allocation Failed!\n"; 
      		exit(1);
      	}
    	if(start == NULL){
        	start = curr = newPtr;
        }
        else{
            curr->next = newPtr;
            curr = newPtr;
        }
    }
    return start;
}
nodeptr insertEl(nodeptr start, int element){ // insert in a sorted linked list
    nodeptr curr, newEl;
    newEl = newNode(element);
    if(start->info >= element){
        newEl->next = start; 
        return newEl;
    }
    for(curr = start; curr->next != NULL && (curr->next->info)<element; curr = curr->next);
    newEl->next = curr->next;
    curr->next = newEl;
    cout<<"After inserting the element:\n";
    print(start);
    return start;
}
nodeptr insertAt(nodeptr start, int element, int pos){ // insert at a position
    int i;
    nodeptr curr, newEl;
    curr = start;
    newEl = newNode(element);
    if(pos == 1){
        newEl->next = start; 
        cout<<"After inserting the new element at position "<<pos<<":\n";
        print(newEl);
        return newEl;
    }
    for(i = 2;curr != NULL;i++){
        if(i == pos){
            newEl->next = curr->next;
            curr->next = newEl;
            cout<<"After inserting the new element at position "<<pos<<":\n";
            print(start);
            return start;
        }
        curr = curr->next;
    }
    cout<<"The position should be between 1 and "<<i-1<<"\n";
    return start;
}
int main()
{
    nodeptr start = createLinkedlist();
    print(start);//print the elements of the linked list
    start = insertEl(start, 9);// insert an element into a sorted linked list
    start = insertAt(start, 6, 3);// insert an element at a position
    return 0;
}
