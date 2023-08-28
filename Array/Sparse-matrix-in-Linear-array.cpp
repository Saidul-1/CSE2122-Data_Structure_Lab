/*Store the element of a lower Triangular matrix A into a linear array*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k=0,x,y;
    int sparse[4][4]={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    // insert the sparse triangular matrix in linear array
    int arr[10];
    for(i=0;i<4;i++){
        for(j=0;j<=i;j++){
            arr[k++]=sparse[i][j];
        }
    }
    // print the element at sparse[3][2] from the linear array
    cout<<"Element at sparse[3][2] = ";
    x=3;y=2;
    if(y>x){cout<<"0\n";}
    else{cout<<arr[x*(x+1)/2+y]<<"\n";}
    // print the elements of the row 4 from the linear array
    cout<<"Elements of the row 4:\n";
    for(i=3*4/2;i<4*5/2;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
