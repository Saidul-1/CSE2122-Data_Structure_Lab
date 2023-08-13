#include<iostream>
using namespace std;

int vertex;
int adj[100][100], mult[100][100];

void multiply(){
	int i,j,k;
	int tmp[100][100];
	//multiply adj with mult
	for(i=0; i<vertex; i++){
		for(j=0; j<vertex; j++){
			int x=0;
			for(k=0; k<vertex; k++){
				x+=(adj[i][k]*mult[k][j]);
			}
			tmp[i][j] = x;
		}
	}
	//copy tmp to mult
	for(int i=0; i<vertex; i++){
		for(int j=0; j<vertex; j++){
			mult[i][j] = tmp[i][j];
		}
	}
}
void paths(){	//print number of paths of variable length from Vi to Vj
	for(int i=0; i<vertex; i++){
		for(int j=0; j<vertex; j++){
			cout<<"V"<<i+1<<"=>"<<"V"<<j+1<<": "<<mult[i][j]<<"\n";
		}
	}
}
void displayAdj(){	//print vertices which are adjacent to Vi
	cout<<"Adjacent vertices:\n";
	for(int i=0; i<vertex; i++){
		cout<<"V"<<i+1<<"=> ";
		for(int j=0; j<vertex; j++){
			if(adj[i][j]){
				cout<<"V"<<j+1<<" ";
			}
		}
		cout<<"\n";
	}
}
int main(){
	cout<<"Enter the number of vertics:\n";
	cin>>vertex;
	//take input and store the matrixe
	for(int i=0; i<vertex; i++){
		for(int j=0; j<vertex; j++){
			cin>>adj[i][j];
			mult[i][j]=adj[i][j];
		}
	}
	displayAdj();
	//print number of paths of variable length from Vi to Vj
	cout<<"Number of paths of length 2:\n";
	multiply();
	paths();

	cout<<"Number of paths of length 3:\n";
	multiply();
	paths();

	cout<<"Number of paths of length 4:\n";
	multiply();
	paths();
	return 0;
}
