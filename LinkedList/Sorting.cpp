/* Md. Saidul Islam 2110776106 */
/* Sort a linked list */
#include <bits/stdc++.h>
using namespace std;

struct node{
    int info;
    struct node *next = NULL;
};
typedef struct node *nodeptr;

nodeptr newNode (int inf){	//create a new node and return the pointer 
    nodeptr p = (nodeptr) malloc (sizeof (struct node));
    if (p == NULL){
        cout << "Unable to allocate memory\n";
        exit (0);
    }
    p->info = inf;
    return p;
}

void sort (nodeptr head){
    if (head == NULL || head->next == NULL){
        return;
    }
    nodeptr current = head, index;
    while (current != NULL){
        index = current->next;
        while (index != NULL){
            if ((index->info) < (current->info)){
                int tmp = index->info;
                index->info = current->info;
                current->info = tmp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void print (nodeptr start){
    for (nodeptr curr = start; curr != NULL; curr = curr->next){
        cout << (curr->info) << " ";
    }
    cout << "\n";
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

