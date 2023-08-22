/* Md. Saidul Islam 2110776106 */
/* delete an element from a sorted linked list and another element from a specific position*/
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
nodeptr deleteEl(nodeptr start, int element){ // delete an element from a sorted linked list
    nodeptr curr;
    if(start->info == element){
        start=start->next; 
        return start;
    }
    for(curr = start; curr->next != NULL && (curr->next->info)<element; curr = curr->next);
    if(curr->next->info != element){
        cout<<"The element not found!\n"; 
        return start;
    }
    curr->next = curr->next->next;
    cout<<"After deleting the element "<<element<<": \n";
    print(start);
    return start;
}
nodeptr deleteAt(nodeptr start, int pos){ // delete an element from a position
    if(pos == 1){
        start = start->next; 
        cout<<"After deleting the element at position "<<pos<<":\n";
        print(start);
        return start;
    }
    int i = 2;
    for(nodeptr curr = start; curr->next != NULL; curr = curr->next){
        if(i++ == pos){
            curr->next = curr->next->next;
            cout<<"After deleting the element at position "<<pos<<":\n";
            print(start);
            return start;
        }
    }
    cout<<"The position should be between 1 and "<<i-1<<"\n";
    return start;
}
int main()
{
    nodeptr start = createLinkedlist();
    //print the elements of the linked list
    cout<<"Elements of the linkedlist:\n";
    print(start);
    start = deleteEl(start, 9);// delete a element from a sorted linked list
    start = deleteAt(start, 3);// delete an element from a position
    return 0;
}
