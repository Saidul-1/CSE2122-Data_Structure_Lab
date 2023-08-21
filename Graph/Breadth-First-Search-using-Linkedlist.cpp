/* Write a program to traverse a Graph represented in Linked List using Breadth-First Search. */
#include<bits/stdc++.h>
using namespace std;

struct node{
	int key;
	struct node *next;
	struct edge *adj;
};
struct edge{
	struct node *dest;
	struct edge *link;
};
typedef struct node* nodeptr;
typedef struct edge* edgeptr;

nodeptr createNodeList(int node){
	nodeptr start = NULL, curr, ptr;
	for(int i=1; i<=node; i++){
		ptr = (nodeptr)malloc(sizeof(struct node));
		if(ptr == NULL){
			cout<<"Memory allocation failed\n";
			exit(0);
		}
		ptr->key = i;
		ptr->next = NULL;
		ptr->adj = NULL;
		if(start == NULL){
			start = curr = ptr;
		}
		else{
			curr->next = ptr;
			curr = curr->next;
		}
	}
	return start;
}
nodeptr findPtr(int key, nodeptr head){
	for(nodeptr ptr = head; ptr != NULL; ptr = ptr->next){
		if(ptr->key == key){
			return ptr;
		}
	}
	cout<<"The node not found!\n";
	return NULL;
}
void createEdge(nodeptr head, int sourceKey, int destKey){
	nodeptr sourcePtr, destPtr;
	sourcePtr = findPtr(sourceKey, head);
	destPtr = findPtr(destKey, head);
	edgeptr newPtr, curr;
	newPtr = (edgeptr)malloc(sizeof(struct edge));
	newPtr->dest = destPtr;
	newPtr->link = NULL;
	if(sourcePtr->adj == NULL){
		sourcePtr->adj = newPtr;
		return;
	}
	for(curr = sourcePtr->adj; curr->link != NULL; curr = curr->link);
	curr->link = newPtr;
}
void printGraph(nodeptr head){
	cout<<"Adjacent Nodes:\n";
	for(nodeptr currNode = head; currNode != NULL; currNode = currNode->next){
		cout<<(currNode->key)<<" => ";
		for(edgeptr currEdge = currNode->adj; currEdge != NULL; currEdge = currEdge->link){
			cout<<(currEdge->dest->key)<<" ";
		}
		cout<<"\n";
	}
}
void printQueue(nodeptr queue[], int front, int rear){
	cout<<"Queue: ";
	while(front<rear){
		cout<<(queue[front++]->key)<<" ";
	}
	cout<<"\n";
}
void bfs(nodeptr head, int status[], int node){
	nodeptr queue[node];
	int front, rear;
	front = rear = 0;
	queue[rear++] = head;
	edgeptr curr;
	while(rear>front){
		printQueue(queue, front, rear);
		status[queue[front]->key] = 2;
		cout<<"Processed: "<<queue[front]->key<<"\n";
		curr = queue[front]->adj;
		while(curr != NULL){
			if(status[curr->dest->key] == 0){
				queue[rear++] = curr->dest;
				status[curr->dest->key] = 1;
			}
			curr = curr->link;
		}
		front++;
	}
}
int main(){
	int node, edge, source, dest;
	cout<<"Enter the number of nodes:\n";
	cin>>node;
	//create the nodelist
	nodeptr start = createNodeList(node);
	//take edges as input and link adjacent nodes
	cout<<"Enter the number of edges:\n";
	cin>>edge;
	cout<<"Enter the source and destination of the edges:\n";
	for(int i=1; i<=edge; i++){
		cin>>source>>dest;
		createEdge(start, source, dest);
	}
	//print adjacent nodes of each node
	printGraph(start);
	//Breadth First Search
	int status [100]={0};
	for(nodeptr curr = start; curr != NULL; curr = curr->next){
		if(status[curr->key] == 0){
			bfs(curr, status, node);
		}
	}
	return 0;
}
