#include <iostream>
using namespace std;

int main()
{
    int i,j,pos,val;
    string name;
    //integer array
    int numbers[10]  =  {21,2,6756,0,34,79,21,63,9,112};
    //string array
    string names[10] = {"Hamim", "Rashed", "Fahim", "Bilal", "Delowar", "Nayeem", "Abdullah", "Mohammad", "Ahad", "Saidul"};
    
    //sort integer array using bubble sort
    for(i=0;i<9;i++){
        for(j=0;j<9-i;j++){
            if(numbers[j]>numbers[j+1]){
                int tmp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=tmp;
            }
        }
    }
    for(i=0; i<10; i++){
        cout<<numbers[i]<<" ";
    }
    cout<<"\n";
    
    //sort string array using bubble sort
    for(i=0;i<9;i++){
        for(j=0;j<9-i;j++){
            if(names[j]>names[j+1]){
                string tmp=names[j];
                names[j]=names[j+1];
                names[j+1]=tmp;
            }
        }
    }
    for(i = 0; i<10; i++){
        cout<<names[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

