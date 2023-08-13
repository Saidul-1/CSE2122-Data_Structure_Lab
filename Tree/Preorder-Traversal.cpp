/* Traverse the tree in Preorder (Root->Left->Right) */
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
void preorderTraverse(nodeptr root){
	if(root == NULL){return;}
	cout<<(root->data)<<" ";
	preorderTraverse(root->left);
	preorderTraverse(root->right);
}
int main(){
	//creating the tree
	nodeptr root = newNode(0);
	root->left = newNode(1);

	root->right = newNode(2);
	root->left->left = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	//traverse the tree in Preorder
	cout<<"Preorder Traversal:\n";
	preorderTraverse(root);
	return 0;
}
