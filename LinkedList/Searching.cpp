/* Md. Saidul Islam 2110776106 */
/* Search for an element in a linked list */
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

int search(int value, nodeptr start){
    for(int pos=1 ;start != NULL; pos++, start = start->next){
        if(start->info == value){
            return pos;
        }
    }
    return -1;
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
    //find the index of the element 9
    int position = search(9, start);
    if(position == -1){cout<<"The element is not found!\n";}
    else{cout<<"The position of the element: "<<position<<"\n";}
    return 0;
}
