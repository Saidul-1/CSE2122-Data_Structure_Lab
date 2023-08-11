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
	if(hashTable[index] == data){
		return true;
	}
	for(int i = index + 1; hashTable[i] != data; i = (i+1) % tableSize){
		if(isOccupied[i] == false || i == index){
			return false;
		}
	}
	return true;
}
int main(){
	int data[] = {53464, 2236, 93, 124647, 77, 31, 55, 5, 21030};
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
