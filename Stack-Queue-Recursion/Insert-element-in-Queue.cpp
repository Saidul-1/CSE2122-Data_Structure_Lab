/* Insert an element into a queue */
#include<iostream>
using namespace std;

int maxSize = 10, front = 0, rear = 0;
void insert(int queue[], int value){
	if(rear >= maxSize){
		cout<<"Overflow!\n";
		exit(0);
	}
	queue[rear++] = value;
}
void display(int queue[]){
	for(int i = front; i < rear; i++){
		cout<<queue[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	int elements[]={10, 5, 0, 999, 3};
	// insert elements in  a queue
	int queue[maxSize];
	for(int i=0;i<5;i++){
		insert(queue, elements[i]);
	}
	cout<<"Elements of the queue:\n";
	display(queue);
	return 0;
}
