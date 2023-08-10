// infix to postfix notation(single-digit)
#include<bits/stdc++.h>
using namespace std;

map<char, int>precedence = { 
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}
};
int postfixEvaluation(string postfix){
	int firstDigit, secondDigit, result = 0;
	stack<int>digits;
	int length = postfix.size();
	for(int i=0;i<length;i++){
		if(postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '^'){
			digits.push(postfix[i]-'0');
		}
		else{
			secondDigit = digits.top();
			digits.pop();
			firstDigit = digits.top();
			digits.pop();
			if(postfix[i] == '+'){
				result = firstDigit+secondDigit;
			}
			if(postfix[i] == '-'){
			result = firstDigit-secondDigit;
			}
			if(postfix[i] == '*'){
			result = firstDigit*secondDigit;
			}
			if(postfix[i] == '/'){
			result = firstDigit/secondDigit;
			}
			if(postfix[i] == '^'){
			result = firstDigit^secondDigit;
			}
			digits.push(result);
		}
	}
	return digits.top();
}
int main(){
	string postfix;
	int result;
	cout<<"Enter the postfix notation:\n";
	cin>>postfix;
	result = postfixEvaluation(postfix);
	cout<<"The evaluated value of "<<postfix<<":\n";
	cout<<result<<"\n";
	return 0;
}
