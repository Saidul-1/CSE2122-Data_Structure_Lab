/*store some data to a hash table using 
Mid Square Method Hash Function and Quadratic Probing Technique. */
#include<bits/stdc++.h>
using namespace std;
#define tableSize 11

int hashTable[tableSize];
bool isOccupied[tableSize] = {false};
int hashFunction(int data){
	if(data<10){
		return data;
	}
	data *= data;
	int length = log10(abs(data))+1;
	if(length % 2){
		data /= pow(10,length / 2);
		data %= 10;
	}
	else{
		data /= pow(10, (length - 1) / 2);
		data %= 100;
	}
	return data % tableSize;
}
bool search(int data){
	int i, j, index = hashFunction(data);
	if(isOccupied[index] && hashTable[index] == data){
		return true;
	}
	for(j=1, i = index + j; i != index && isOccupied[i];j+=2, i = (i+j) % tableSize){
		if(hashTable[i] == data){
			return true;
		}
	}
	return false;
}
int main(){
	int data[] = {5364, 2236, 93, 12447, 772, 31, 55, 0, 2103};
	int i, j, index, toSearch;
	//store the data in hash table
	for(i = 0; i<9; i++){
		for(j=1, index = hashFunction(data[i]); isOccupied[index]; j += 2){
			index = (index + j) % tableSize;
		}
		hashTable[index] = data[i];
		isOccupied[index] = true;
	}
	//search for an element
	cout<<"Enter the data to search:\n";
	scanf("%d",&toSearch);
	if(search(toSearch)){
		cout<<toSearch<<" Found!\n";
	}
	else{
		cout<<toSearch<<" Not Found!\n";
	}
	return 0;
}
