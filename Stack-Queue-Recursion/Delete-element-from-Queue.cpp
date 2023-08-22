/* Delete an element from a queue */
#include<iostream>
using namespace std;

int maxSize = 10, front = 0, rear = 0, queueSize = 0;
void insert(int queue[], int value){
	if(queueSize == maxSize){
		cout<<"Overflow!\n";
		exit(1);
	}
	queue[rear] = value;
	rear = (rear+1)%maxSize;
	queueSize++;
}
void pop(int queue[]){
	if(queueSize == 0){
		cout<<"The queue is empty!\n";
	}
	else{
		front = (front+1)%maxSize;
		queueSize--;
	}
}
void display(int queue[]){
	for(int i = 0; i < queueSize; i++){
		cout<<queue[(front+i)%maxSize]<<" ";
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
	// delete an element
	pop(queue);
	cout<<"Elements of the queue after deletion:\n";
	display(queue);
	return 0;
}
