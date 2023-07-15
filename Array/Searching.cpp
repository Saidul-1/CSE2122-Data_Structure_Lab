#include <iostream>
using namespace std;

int main()
{
    int i,pos,val;
    string name;
    // sorted integer array
    int numbers[10]  =  {0, 12, 25, 25, 33, 50, 77, 88, 100, 139};
    // sorted string array
    string names[10] = {"Abdullah", "Ahad", "Bilal", "Delowar", "Fahim", "Karim", "Mohammad", "Nayeem", "Rashed", "Saidul"};
    
    //binary search 77 in a sorted integer array
    val=77; pos=-1;
    int mid,l=0,r=9;
    while(r>=l){
        mid=(l+r)/2;
        if(numbers[mid]==val){pos=mid; break;}
        if(numbers[mid]>val){r=mid-1;}
        else if(numbers[mid]<val){l=mid+1;}
    }
    if(pos==-1){cout<<"The item not found!\n";}
    else{cout<<pos<<"\n";}
    
    //binary search "Karim" in a sorted string array
    name = "Karim"; pos=-1;
    l=0,r=9;
    while(r>=l){
        mid=(l+r)/2;
        if(names[mid]==name){pos=mid; break;}
        if(names[mid]>name){r=mid-1;}
        else if(names[mid]<name){l=mid+1;}
    }
    if(pos==-1){cout<<"The item not found!\n";}
    else{cout<<pos<<"\n";}
    
    return 0;
}
