// infix to postfix notation(single-digit)
#include<bits/stdc++.h>
using namespace std;

map<char, int>precedence = { 
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}
};
int postfixEvaluation(string postfix){
	stack<int>operand;
	int operand1, operand2;
	for(int i=0; i<postfix.size(); i++){
		if(postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '^'){
			operand.push(postfix[i]-'0');
		}
		else{
			operand2 = operand.top();
			operand.pop();
			operand1 = operand.top();
			operand.pop();
			if(postfix[i] == '+'){
				operand.push(operand1 + operand2);
			}
			else if(postfix[i] == '-'){
				operand.push(operand1 - operand2);
			}
			else if(postfix[i] == '*'){
				operand.push(operand1 * operand2);
			}
			else if(postfix[i] == '/'){
				operand.push(operand1 / operand2);
			}
			else{
				operand.push(pow(operand1, operand2));
			}
		}
	}
	return operand.top();
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
