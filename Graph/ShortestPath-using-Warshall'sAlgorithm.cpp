/* Find out the shortest path of a Weighted Graph G with m nodes V1, V2, … ,Vm 
and weight of each edge is w(e) using Warshall’s Algorithm */
#include<iostream>
using namespace std;

int vertex, INF = 1e9;
int weight[100][100], shortestPath[100][100];
void displayMat(int mat[100][100]){	//print Matrix
	for(int i=0; i<vertex; i++){
		for(int j=0; j<vertex; j++){
			if(mat[i][j]==1e9){
				cout<<"INF ";
			}
			else{
				cout<<mat[i][j]<<" ";
			}
		}
		cout<<"\n";
	}
}
int main(){
	int i,j,k;
	cout<<"Enter the number of vertics:\n";
	cin>>vertex;
	//take input and store the matrixe
	cout<<"Enter the weighted matrix\n";
	for(i=0; i<vertex; i++){
		for(j=0; j<vertex; j++){
			cin>>weight[i][j];
			if(weight[i][j]==0){
				shortestPath[i][j]=INF;
			}
			else{
				shortestPath[i][j]=weight[i][j];
			}
		}
	}
	for(k=0;k<vertex;k++){
		for(i=0;i<vertex;i++){
			for(j=0;j<vertex;j++){
				if(shortestPath[i][j] > (shortestPath[i][k] + shortestPath[k][j])){
					shortestPath[i][j] = (shortestPath[i][k] + shortestPath[k][j]);
				}	
			}
		}
	}
	cout<<"The shortest path matrix:\n";
	displayMat(shortestPath);
	return 0;
}

