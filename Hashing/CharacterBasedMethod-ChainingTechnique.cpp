/*store some data to a hash table using 
Character-Based Method Hash Function and Chaining Technique. */
#include<bits/stdc++.h>
using namespace std;
#define tableSize 11

struct node{
	string info;
	struct node* next = NULL;
};
typedef struct node* nodeptr;
nodeptr hashTable[tableSize];

nodeptr newNode(string data){
	nodeptr ptr = (nodeptr)malloc(sizeof(node));
	if(ptr == NULL){
		cout<<"Memory Limit Exit";
		exit(0);
	}
	ptr -> info = data;
	return ptr;
}
int hashFunction(string data){
	int sum = 0;
	for(int i = 0; i < data.size(); i++){
		sum += data[i];
	}
	return sum % tableSize;
}
bool search(string data){
	int index = hashFunction(data);
	nodeptr tmp = hashTable[index];
	while(tmp != NULL){
		if(tmp -> info == data){
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}
int main(){
	string data[] = {"Computer", "Science", "and", "Engineering", "University", "of", "Rajshahi"};
	string toSearch;
	nodeptr tmp, ptr;
	//store the data in hash table
	for(int i = 0; i<7; i++){
		int index = hashFunction(data[i]);
		ptr = newNode(data[i]);
		tmp = hashTable[index];
		if(tmp == NULL){
			hashTable[index] = ptr;
		}
		else{
			while(tmp->next!=NULL){
				tmp = tmp->next;
			}
			tmp->next = ptr;
		}
	}
	//search for an element
	cout<<"Enter the data to search:\n";
	cin>>toSearch;
	if(search(toSearch)){
		cout<<toSearch<<" Found!\n";
	}
	else{
		cout<<toSearch<<" Not Found!\n";
	}
	return 0;
}
