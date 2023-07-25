// Push an Item onto a Stack
#include <bits/stdc++.h>
using namespace std;

int push(int stack[], int top, int value){
    stack[++top]=value;
    return top;
}
int main()
{
    int elements[]={3,0,56,12,7};
    int mx=10,top=-1;
    int stack[mx];
    //push the elements in the stack
    for(int i=0;i<5 && top<mx;i++){
        top = push(stack, top, elements[i]);
    }
    //print the elements
    cout<<"Elements of the stack:\n";
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    return 0;
}

