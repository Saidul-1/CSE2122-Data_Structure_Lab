#include <iostream>
using namespace std;

int main()
{
    int i,j;
    string name;
    // marge integer array
    int numbersA[4] = {34,0,2,132};
    int numbersB[6] = {5,23,293,24,96,78};
    int margedNumbers[10];
    for(i=0;i<4;i++){
        margedNumbers[i]=numbersA[i];
    }
    for(j=0;j<6;j++){
        margedNumbers[i++]=numbersB[j];
    }
    cout<<"Marged integer array:\n";
    for(i=0;i<10;i++){
        cout<<margedNumbers[i]<<" ";
    }
    cout<<"\n";
    // marge string array
    string namesA[7] = {"Delowar", "Abdullah", "Mohammad", "Rashed", "Bilal",  "Fahim", "Karim"};
    string namesB[3] = {"Nayeem", "Ahad", "Saidul"};
    string margedNames[10];
    for(i=0;i<7;i++){
        margedNames[i]=namesA[i];
    }
    for(j=0;j<3;j++){
        margedNames[i++]=namesB[j];
    }
    cout<<"Marged string array:\n";
    for(i=0;i<10;i++){
        cout<<margedNames[i]<<" ";
    }
    return 0;
}
