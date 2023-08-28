/* Write a program to delete an element from a heap(max-heap is used). */
#include<bits/stdc++.h>
using namespace std;

int heap[100] = {0};
void insert(int data, int heapSize){
	int parent, pos=heapSize;
	while(pos>0){
		parent = (pos-1)/2;
		if(heap[parent]>=data){
			heap[pos] = data;
			return;
		}
		heap[pos] = heap[parent];
		pos = parent;
	}
	heap[pos] = data;
}
bool remove(int data, int heapSize){
	int pos;
	for(pos=0; pos<heapSize; pos++){
		if(heap[pos] == data){
			break;
		}
	}
	if(pos==heapSize){
		cout<<"The data "<<data<<" is not found!\n";
		return false;
	}
	while(pos<heapSize/2){		//travarse upto the last non-leaf node
		int left=pos*2+1, right = pos*2+2;
		if(heap[left]<=heap[right]){
			heap[pos]=heap[right];
			pos = right;
		}
		else{
			heap[pos]=heap[left];
			pos = left;
		}
	}
	heap[pos] = heap[heapSize-1];
	return true;
}
void displayTree(int tree[], int size){		//works better with single-digit nodes.
	int i, j, space, lineGap, level = log2(size)+1;
	for(i=0; i<level; i++){					//levels
		for(j=0;(j<(1<<i) && size--); j++){	//nodes of each level
			space = (1<<(level-i))-1;
			if(j == 0){
				space /= 2;
			}
			while(space--){
				cout<<" ";
			}
			cout<<tree[(1<<i)-1+j];
		}
		for(lineGap=0; lineGap<(1<<(level-i-2)); lineGap++){
			cout<<"\n";
		}
	}
	cout<<"\n";
}
int main(){
	int data[] = {5, 9, 0, 3, 1, 2, 6, 1, 4, 7};
	int toDelete, heapSize = 0;
	for(int i=0; i<10; i++){
		insert(data[i], heapSize);
		heapSize++;
	}
	displayTree(heap, heapSize);

	cout<<"Insert the element to delete:\n";
	cin>>toDelete;
	heapSize-=remove(toDelete, heapSize);
	displayTree(heap, heapSize);
	return 0;
}

