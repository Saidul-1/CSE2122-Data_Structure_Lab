/* Md. Saidul Islam 2110776106 */
/* Sort a linked list */
#include <bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next;
};
typedef struct node *nodeptr;

nodeptr newNode (int inf){	//create a new node and return the pointer 
    nodeptr ptr = (nodeptr) malloc (sizeof (struct node));
    if (ptr == NULL){
        cout << "Memory Allocation Failed!\n";
        exit (1);
    }
    ptr->info = inf;
    ptr->next = NULL;
    return ptr;
}
void print (nodeptr start){
    for (nodeptr curr = start; curr != NULL; curr = curr->next){
        cout << (curr->info) << " ";
    }
    cout << "\n";
}
void sort (nodeptr head){
    if (head == NULL || head->next == NULL){
        return;
    }
    nodeptr current = head, index;
    while (current != NULL){
        index = head;
        while (index->next != NULL){
            if ((index->info) > (index->next->info)){
                int tmp = index->info;
                index->info = index->next->info;
                index->next->info = tmp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
int main (){
    int elements[] = { 5, 3, 9, 42, 0, 10 };
    nodeptr start, curr, newPtr;
    //create the linked list and add the elements from the array
    start = curr = NULL;
    for (int i = 0; i < 6; i++){
        newPtr = newNode (elements[i]);
        if (start == NULL){
	        start = curr = newPtr;
	    }
        else{
	        curr->next = newPtr;
	        curr = newPtr;
	    }
    }
    //print the elements of the linked list
    cout << "Elements of the linked list\n";
    print (start);
    sort (start);   //sort the list;
    //print elements after sorting
    cout << "Elements after sorting:\n";
    print (start);
    return 0;
}

