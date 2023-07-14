#include <iostream>
using namespace std;

int main()
{
    int i,pos,val;
    string name;
    // sorted string array
    string names[10] = {"Abdullah", "Bilal", "Delowar", "Fahim", "Hamim", "Karim", "Mohammad", "Nayeem", "Rashed", "Saidul"};
    
    //Delete "Karim" from a sorted string array
    name = "Karim";
    for(pos = 0; names[pos]<name; pos++);
    for(i = pos; i<9; i++){
        names[i] = names[i+1];
    }
    for(i = 0; i<9; i++){
        cout<<names[i]<<" ";
    }
    cout<<"\n";
    
    //Delete the item at position 2
    pos = 2;
    for(i = pos-1; i<8; i++){
        names[i] = names[i+1];
    }
    for(i = 0; i<8; i++){
        cout<<names[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

