/*Matrix: Addition/Subtraction/Multiplication of two matrices.*/
#include <bits/stdc++.h>
using namespace std;

void addition(int rowA, int colA, int matA[20][20], int matB[20][20]){
    int add[rowA][colA];
    cout<<"matrix A + matrix B:\n";
    for(int i=0;i<rowA;i++){
        for(int j=0;j<colA;j++){
            add[i][j]=matA[i][j]+matB[i][j];
            cout<<add[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void subtraction(int rowA, int colA, int matA[20][20], int matB[20][20]){
    int sub[rowA][colA];
    cout<<"matrix A - matrix B:\n";
    for(int i=0;i<rowA;i++){
        for(int j=0;j<colA;j++){
            sub[i][j]=matA[i][j]-matB[i][j];
            cout<<sub[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void multiplication(int rowA, int colA, int colB, int matA[20][20], int matB[20][20]){
    int mult[rowA][colA];
    cout<<"matrix A * matrix B:\n";
    for(int i=0;i<rowA;i++){
        for(int j=0;j<colB;j++){
            int sum=0;
            for(int k=0;k<colA;k++){
                sum+=(matA[i][k]*matB[k][j]);
            }
            mult[i][j]=sum;
            cout<<mult[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    int i,j,k,l,m,n,rowA,colA,rowB,colB;
    int matA[20][20], matB[20][20];
    //assign values of the matrices
    cout<<"Enter the number of row and the number of column of the matrix A:\n";
    cin>>rowA>>colA;
    cout<<"Enter the number of row and the number of column of the matrix B:\n";
    cin>>rowB>>colB;
    cout<<"Enter the elements of matrix A:\n";
    for(i=0;i<rowA;i++){
        for(j=0;j<colA;j++){
            cin>>matA[i][j];
        }
    }
    cout<<"Enter the elements of matrix B:\n";
    for(i=0;i<rowB;i++){
        for(j=0;j<colB;j++){
            cin>>matB[i][j];
        }
    }
    if(rowA!=rowB || colA!=colB){
        cout<<"Addition and Subtraction are not possible\n";
    }
    else{
        addition(rowA,colA,matA,matB);
        subtraction(rowA,colA,matA,matB);
    }
    if(colA!=rowB){
        cout<<"Multiplication is not possible\n";
    }
    else{
        multiplication(rowA,colA,colB,matA,matB);
    }
    return 0;
}
