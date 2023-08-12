/*store some data to a hash table using 
Folding Method Hash Function and Linear Probing Technique. */
#include<iostream>
using namespace std;
#define tableSize 11

int hashTable[tableSize];
bool isOccupied[tableSize] = {false};
int hashFunction(int data){
	int sum = 0;
	while(data>0){
		sum += data%100;
		data/=100;
	}
	return sum % tableSize;
}
bool search(int data){
	int index = hashFunction(data);
	if(isOccupied[index] == true && hashTable[index] == data){
		return true;
	}
	for(int i = index + 1; i != index && isOccupied[i] == true; i = (i+1) % tableSize){
		if(hashTable[i] == data){
			return true;
		}
	}
	return false;
}
int main(){
	int data[] = {53464, 2236, 93, 124647, 772, 31, 55, 550, 2103};
	int index, toSearch;
	//store the data in hash table
	for(int i = 0; i<9; i++){
		index = hashFunction(data[i]);
		while(isOccupied[index]){
			index = (index+1) % tableSize;
		}
		hashTable[index] = data[i];
		isOccupied[index] = true;
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
