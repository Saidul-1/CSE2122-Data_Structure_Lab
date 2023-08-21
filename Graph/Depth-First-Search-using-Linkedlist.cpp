/* Write a program to traverse a Graph represented in Linked List using Depth-First Search. */
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
void printStack(nodeptr stack[], int top){
	cout<<"Stack: ";
	for(int i=0; i<=top; i++){
		cout<<stack[i]->key<<" ";
	}
	cout<<"\n";
}

void dfs(nodeptr head, int status[], int node){
	nodeptr stack[node];
	int top = -1;
	stack[++top] = head;
	edgeptr curr;
	while(top>=0){
		printStack(stack, top);
		status[stack[top]->key] = 2;
		cout<<"Processed: "<<stack[top]->key<<"\n";
		curr = stack[top]->adj;
		top--;//pop the top node from the stack
		while(curr != NULL){
			if(status[curr->dest->key] == 0){
				stack[++top] = curr->dest;//push the node to the stack
				status[curr->dest->key] = 1;
			}
			curr = curr->link;
		}
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
			dfs(curr, status, node);
		}
	}
	return 0;
}
