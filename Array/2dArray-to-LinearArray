/*Copy elements of a 2D array into a 1D/linear array and print the elements of group 3 from the 1D array.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,l,m,n;
    int array[3][4]={
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    int rowArray[12], colArray[12];
    //assign values of the 2D array into linear array(column-wise and row-wise)
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            rowArray[i*4+j]=array[i][j];
            colArray[j*3+i]=array[i][j];
        }
    }
    //print row 3 using the linear array
    cout<<"row 3:\n";
    for(i=2*4;i<3*4;i++){
        cout<<rowArray[i]<<" ";
    }
    cout<<"\n";
    //print column 3 using the linear array
    cout<<"column 3:\n";
    for(i=2*3;i<3*3;i++){
        cout<<colArray[i]<<" ";
    }
    return 0;
}
