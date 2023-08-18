#include<iostream>
using namespace std;

int vertex;
int adj[100][100], path[100][100];
void displayMat(int mat[100][100]){	//print Matrix
	for(int i=0; i<vertex; i++){
		for(int j=0; j<vertex; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	int i,j,k;
	cout<<"Enter the number of vertics:\n";
	cin>>vertex;
	//take input and store the matrixe
	for(i=0; i<vertex; i++){
		for(j=0; j<vertex; j++){
			cin>>adj[i][j];
			if(adj[i][j]==0){path[i][j]=0;}
			else{path[i][j]=1;}
		}
	}
	for(k=0;k<vertex;k++){
		for(i=0;i<vertex;i++){
			for(j=0;j<vertex;j++){
				path[i][j] = (path[i][j] | (path[i][k] & path[k][j]));
			}
		}
	}
	cout<<"The path matrix:\n";
	displayMat(path);
	return 0;
}

