/* Traverse the tree in Inorder (Left->Root->Right) */
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
void inorderTraverse(nodeptr root){
	if(root == NULL){return;}
	inorderTraverse(root->left);
	cout<<(root->data)<<" ";
	inorderTraverse(root->right);
}
int main(){
	//creating the tree
	nodeptr root = newNode(0);
	root->left = newNode(1);

	root->right = newNode(2);
	root->left->left = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	//traverse the tree in inorder
	cout<<"Inorder Traversal:\n";
	inorderTraverse(root);
	return 0;
}
