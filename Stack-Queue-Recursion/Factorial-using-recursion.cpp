//  Md. Saidul Islam 2110776106 
//  Calculate the factorial of a given number using recursive technique
#include <iostream>
using namespace std;

long factorial(int n){
    if(n <= 1){
        return 1;
    }
    return n*factorial(n-1);
}
int main()
{
    int num, sign;
    cout<<"Enter the number:\n";
    cin>>num;
    sign = num / abs(num);
    if(num > 20){
        "Overflow!\nThe number should be less than 20\n";
    }
    else{
        cout<<"Factorial of "<<num<<" = "<<sign*factorial(abs(num))<<"\n";
    }
    return 0;
}

