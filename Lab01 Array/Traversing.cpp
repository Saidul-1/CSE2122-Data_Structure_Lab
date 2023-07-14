#include<iostream>
#include<math.h>
using namespace std;

int main(){
	//Declare the array and assign value
    int array[10]={3,23,5,0,124,1,76,36,90,14};
    
    //Maximum & Minimum Value
    int max=array[0], min=array[0];
    for(int i=1;i<10;i++){
    	if(array[i]>max){max=array[i];}
    	if(array[i]<min){min=array[i];}
    }
    cout<<"Maximum Value: "<<max<<"\n";
    cout<<"Minimum Value: "<<min<<"\n";
    
    //Total & Average Value
    int sum=0,avg;
    for(int i=0;i<10;i++){
    	sum+=array[i];
    }
    cout<<"Total Value: "<<sum<<"\n";
    cout<<"Average Value: "<<avg<<"\n";
    
    //sin value
    for(int i=0;i<10;i++){
    	cout<<"sin value of "<<array[i]<<": "<<sin(array[i])<<"\n";
    }
    return 0;
}
