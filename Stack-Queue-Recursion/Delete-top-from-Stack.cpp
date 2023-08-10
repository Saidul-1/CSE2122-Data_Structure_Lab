/* Delete the top element from a Stack */
#include <bits/stdc++.h>
using namespace std;

int mxSize = 5, top = -1;
void push(int stackA[], int value){
    if(top >= mxSize){
        cout<<"Overflow\n";
        return;
    }
    stackA[++top] = value;
}
int pop(int stackA[]){
    if(top < 0){
        cout<<"The Stack is already empty!\n";
        exit(0); 
    }
    top--;
    return stackA[top+1];
}
int main()
{
    int elements[] = {3,0,56,12,7};
    int stackA[mxSize];
    //push the elements in the stack
    for(int i = 0;i < 5;i++){
        push(stackA, elements[i]);
    }
    //print the elements
    cout<<"Elements of the stack:\n";
    for(int i = top;i >= 0;i--){
        cout<<stackA[i]<<" ";
    }
    cout<<"\n";
    //delete the top element
    int popped = pop(stackA);
    cout<<"The deleted element is "<<popped<<"\n";
    return 0;
}

