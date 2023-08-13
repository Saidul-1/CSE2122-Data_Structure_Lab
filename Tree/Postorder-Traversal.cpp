/* Traverse the tree in Postorder (Left->Right->Root) */
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* left = NULL;
	struct node* right = NULL;
};
typedef struct node* nodeptr;
nodeptr newNode(int data){
	nodeptr newptr = (nodeptr)malloc(sizeof(struct node));
	newptr->data = data;
	return newptr;
}
void postorderTraverse(nodeptr root){
	if(root == NULL){return;}
	postorderTraverse(root->left);
	postorderTraverse(root->right);
	cout<<(root->data)<<" ";
}
int main(){
	//creating the tree
	nodeptr root = newNode(0);
	root->left = newNode(1);

	root->right = newNode(2);
	root->left->left = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	//traverse the tree in postorder
	cout<<"Postorder Traversal:\n";
	postorderTraverse(root);
	return 0;
}
