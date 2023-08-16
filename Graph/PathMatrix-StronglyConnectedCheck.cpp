#include <iostream>
#include <algorithm>
using namespace std;

int vertex;
bool pathMat[100][100];
int Br[100][100][100];

void multiply(int a, int b, int c){
	int i, j, k;
	int tmp[100][100];
	//multiply adj with mult
	for(i=0; i<vertex; i++){
		for(j=0; j<vertex; j++){
			int x = 0;
			for(k = 0; k<vertex; k++){
				x +=( Br[a][i][k]*Br[b][k][j]);
			}
			Br[c][i][j] = x;
		}
	}
}
int main(){
	cout<<"Enter the number of vertics:\n";
	cin>>vertex;
	//take input and store the adjacency matrixe
	for(int i=0; i<vertex; i++){
		for(int j=0; j<vertex; j++){
			cin>>Br[0][i][j];
			Br[1][i][j] = Br[0][i][j];
		}
	}
	//calculate Br(A,A^2,A^3,...A^vertex)
	for(int i=2;i<=vertex;i++){
		multiply(0,i-1,i);
	}

	//calculate path matrix
	for(int k=1;k<=vertex;k++){
		for(int i=0; i<vertex; i++){
			for(int j=0; j<vertex; j++){
				pathMat[i][j] |= Br[k][i][j];
			}
		}
	}
	//check whether the matrix is strongly connected
	int path = 0;
	for(int i=0; i<vertex; i++){
		for(int j=0; j<vertex; j++){
			path += pathMat[i][j];
		}
	}
	if(vertex == 1 || path == vertex*vertex){
		cout<<"The Matrix is Strongly Connected\n";
	}
	else{
		cout<<"The Matrix is not Strongly Connected\n";
	}
	return 0;
}
