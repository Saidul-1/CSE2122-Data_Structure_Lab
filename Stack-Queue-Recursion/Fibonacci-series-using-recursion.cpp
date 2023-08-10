// Md. Saidul Ilsam 2110776106
// Fibonacci series using recursive technique
#include <iostream>
using namespace std;

long fib_series[10000];
long fibonacci(int n){
    if(!fib_series[n]){
        if(n<=1){
            fib_series[n] = n;
        }
        else{
            fib_series[n] = (fibonacci(n-1) + fibonacci(n-2));
        }
    }
    return fib_series[n];
}
int main()
{
    int num;
    cout<<"Enter a number:\n";
    cin>>num;
    fibonacci(num);
    // print the values
    for(int i=0;i<=num;i++){
        cout<<fib_series[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

