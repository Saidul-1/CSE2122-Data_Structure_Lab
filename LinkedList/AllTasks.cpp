//LinkedList
#include<bits/stdc++.h>
using namespace std;

struct node{
   int info;
   struct node *ptr = NULL;
};
typedef struct node *nodeptr;

nodeptr newNode(int inf){
   nodeptr p;
   p=(nodeptr)malloc(sizeof(struct node));
   if(p!=NULL){
       p->info=inf;
   }
   return p;
}
nodeptr createList(int n){
    int i,inf;
    nodeptr start,curr,newPtr;
    cout<<"Enter values\n";
    start=curr=NULL;
    for(i=1;i<=n;i++){
      cin>>inf;
      newPtr = newNode(inf);
      if(newPtr==NULL){cout<<"Memory Limit Exit\n";}
      else{
         if(start==NULL){
            start=curr=newPtr;
         }
         else{
            curr->ptr = newPtr;
            curr=newPtr;
         }
      }
    }
    return start;
}
void print(nodeptr start){
    nodeptr curr,newPtr;
    cout<<"Elements of the linked list:\n";
    curr=start;
    while(curr!=NULL){
      cout<<curr->info<<" ";
      curr=curr->ptr;
    }
    cout<<"\n";
}
int search(int value,nodeptr start){
    int pos=1;
    nodeptr curr=start;
    while(curr!=NULL){
        if(curr->info==value){
            cout<<"Position: "<<pos<<"\n";
            return pos;
        }
        curr=curr->ptr;
        pos++;
    }
    cout<<"Not Found!\n";
    return -1;
}
nodeptr insertAt(nodeptr start, int pos, int inf){
    nodeptr curr=start, addedNode = newNode(inf);
    int index;
    if(pos==1){
        addedNode->ptr=curr;
        start=addedNode;
    }
    for(index=2;curr!=NULL;index++){
        if(index==pos){
            addedNode->ptr=curr->ptr;
            curr->ptr=addedNode;
            break;
        }
        curr=curr->ptr;
    }
    if(curr==NULL){cout<<"The position should be less than "<<index<<".\n";}
    return start;
}
nodeptr remove(nodeptr start, int pos){
    nodeptr curr=start;
    if(pos==1){
        start=start->ptr;
    }
    for(int i=2;curr->ptr!=NULL;i++){
        if(i==pos){
            curr->ptr=curr->ptr->ptr;
            break;
        }
        curr=curr->ptr;
    }
    if(curr->ptr==NULL){cout<<"The position is not available.\nThe value can't be removed.\n";}
    return start;
}
void sort (nodeptr head){
    if (head == NULL || head->ptr == NULL){
        return;
    }
    nodeptr current = head, index;
    while (current != NULL){
        index = current->ptr;
        while (index != NULL){
            if ((index->info) < (current->info)){
                int tmp = index->info;
                index->info = current->info;
                current->info = tmp;
            }
            index = index->ptr;
        }
        current = current->ptr;
    }
}

int main(){
    int n,value,pos;
    nodeptr list1;
    cout<<"How many node do you want to add?\n";
    cin>>n;
    //creating
    list1=createList(n);
    print(list1);
    //searching
    cout<<"Which value do you want to search?\n";
    cin>>value;
    pos=search(value, list1);
    //inserting
    cout<<"To add a new node enter the position and the value\n";
    cin>>pos>>value;
    list1=insertAt(list1, pos, value);
    print(list1);
    //deleting
    cout<<"To remove a node enter the position of the node\n";
    cin>>pos;
    list1=remove(list1, pos);
    print(list1);
    //sorting
    sort(list1);
    cout<<"The sorted linked list:\n";
    print(list1);
    return 0;
}

