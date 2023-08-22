//LinkedList: create, insert, remove, search, sort, print
#include<bits/stdc++.h>
using namespace std;

struct node{
   int info;
   struct node *ptr;
};
typedef struct node *nodeptr;

nodeptr newNode(int inf){
   nodeptr p;
   p = (nodeptr)malloc(sizeof(struct node));
   if(p != NULL){
       p->info = inf;
       p->ptr = NULL;
   }
   return p;
}
nodeptr createList(int n){
    int i, inf;
    nodeptr start, curr, newPtr;
    cout<<"Enter values\n";
    start = curr = NULL;
    for(i=1; i<=n; i++){
	    cin>>inf;
	    newPtr = newNode(inf);
	    if(newPtr == NULL){
	       	cout<<"Memory Allocation Failed!\n";
	       	exit(1);
	    }
 	    if(start == NULL){
        	start = curr = newPtr;
    	}
    	else{
        	curr->ptr = newPtr;
        	curr = curr->ptr;
    	}
    }
    return start;
}
void print(nodeptr start){
    nodeptr curr, newPtr;
    curr = start;
    while(curr != NULL){
    	cout<<(curr->info)<<" ";
      	curr = curr->ptr;
    }
    cout<<"\n";
}
int search(int value,nodeptr start){
    int pos = 1;
    nodeptr curr = start;
    while(curr != NULL){
        if(curr->info == value){
            cout<<"Position: "<<pos<<"\n";
            return pos;
        }
        curr = curr->ptr;
        pos++;
    }
    cout<<"Not Found!\n";
    return -1;
}
nodeptr insertAt(nodeptr start, int pos, int inf){
    nodeptr curr=start, addedNode = newNode(inf);
    int index;
    if(pos == 1){
        addedNode->ptr = curr;
        start = addedNode;
    }
    for(index = 2; curr != NULL; index++){
        if(index == pos){
            addedNode->ptr = curr->ptr;
            curr->ptr = addedNode;
            break;
        }
        curr = curr->ptr;
    }
    if(curr == NULL){cout<<"The position should be less than "<<index<<".\n";}
    return start;
}
nodeptr deleteAt(nodeptr start, int pos){ // delete an element from a position
    if(pos == 1){
        start = start->ptr; 
        cout<<"After deleting the element at position "<<pos<<":\n";
        print(start);
        return start;
    }
    int i = 2;
    for(nodeptr curr = start; curr->ptr != NULL; curr = curr->ptr){
        if(i++ == pos){
            curr->ptr = curr->ptr->ptr;
            cout<<"After deleting the element at position "<<pos<<":\n";
            print(start);
            return start;
        }
    }
    cout<<"The position should be between 1 and "<<i-1<<"\n";
    return start;
}
void sort (nodeptr head){
    if (head == NULL || head->ptr == NULL){
        return;
    }
    nodeptr current = head, index;
    while (current != NULL){
        index = head;
        while (index->ptr != NULL){
            if ((index->info) > (index->ptr->info)){
                int tmp = index->info;
                index->info = index->ptr->info;
                index->ptr->info = tmp;
            }
            index = index->ptr;
        }
        current = current->ptr;
    }
}

int main(){
    int n, value, pos;
    nodeptr list1;
    cout<<"How many node do you want to add?\n";
    cin>>n;
    //creating
    list1 = createList(n);
    cout<<"Elements of the linked list:\n";
    print(list1);
    //searching
    cout<<"Which value do you want to search?\n";
    cin>>value;
    pos = search(value, list1);
    //inserting
    cout<<"To add a new node enter the position and the value\n";
    cin>>pos>>value;
    list1 = insertAt(list1, pos, value);
    cout<<"After adding the new element to the linked list:\n";
    print(list1);
    //deleting
    cout<<"To remove a node enter the position of the node\n";
    cin>>pos;
    list1 = deleteAt(list1, pos);
    //sorting
    sort(list1);
    cout<<"The sorted linked list:\n";
    print(list1);
    return 0;
}

