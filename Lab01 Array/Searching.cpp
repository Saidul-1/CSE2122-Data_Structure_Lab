//WARNING: works properly only in c++20
#include <iostream>
using namespace std;

void binarySearch(auto* array, auto val){
    int mid,l=0,r=9,pos=-1;
    while(r>=l){
        mid=(l+r)/2;
        if(array[mid]==val){pos=mid; break;}
        if(array[mid]>val){r=mid-1;}
        else if(array[mid]<val){l=mid+1;}
    }
    if(pos==-1){cout<<"The item not found!\n";}
    else{cout<<pos<<"\n";}
}
int main()
{
    int i,pos,val=77;
    string name="Karim";
    // sorted integer array
    int numbers[10]  =  {0, 12, 25, 25, 33, 50, 77, 88, 100, 139};
    // sorted string array
    string names[10] = {"Abdullah", "Ahad", "Bilal", "Delowar", "Fahim", "Karim", "Mohammad", "Nayeem", "Rashed", "Saidul"};
    
    binarySearch(numbers,val);
    binarySearch(names,name);

    return 0;
}

