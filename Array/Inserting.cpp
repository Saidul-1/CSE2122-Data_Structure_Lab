#include <iostream>
using namespace std;

int main()
{
    int i,pos,val;
    string name;
    // sorted integer array
    int numbers[12]  =  {0, 12, 25, 25, 33, 50, 87, 88, 100, 139};
    // sorted string array
    string names[12] = {"Abdullah", "Ahad", "Bilal", "Delowar", "Fahim", "Hamim", "Mohammad", "Nayeem", "Rashed", "Saidul"};
    
    // insert 54 to a sorted integer array
    val=54;
    for(pos=0; numbers[pos]<val; pos++);
    for(i=10; i>pos; i--){
        numbers[i] = numbers[i-1];
    }
    numbers[pos] = val;
    for(i=0; i<11; i++){
        cout<<numbers[i]<<" ";
    }
    cout<<"\n";
    
    //insert "Rahim" to a sorted string array
    name = "Rahim";
    for(pos = 0; names[pos]<name; pos++);
    for(i = 10; i>pos; i--){
        names[i] = names[i-1];
    }
    names[pos] = name;
    for(i = 0; i<11; i++){
        cout<<names[i]<<" ";
    }
    cout<<"\n";
    
    // insert 99 at position 5
    val = 99; pos = 5;
    for(i = 11; i>=pos; i--){
        numbers[i] = numbers[i-1];
    }
    numbers[pos-1] = val;
    for(i = 0; i<12; i++){
        cout<<numbers[i]<<" ";
    }
    cout<<"\n";
    
    //insert "Karim" at position 5
    name = "Karim"; pos = 5;
    for(i = 11; i>=pos; i--){
        names[i] = names[i-1];
    }
    names[pos-1] = name;
    for(i = 0; i<12; i++){
        cout<<names[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

