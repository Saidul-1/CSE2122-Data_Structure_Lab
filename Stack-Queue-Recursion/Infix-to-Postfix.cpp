/* Transform an Infix expression into Postfix expression(single-digit) */
#include<bits/stdc++.h>
using namespace std;

map<char, int>precedence = { 
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}
};
string infixToPostfix(string infix){
	string postfix = "";
	stack<char>operatorStack;
	int length = infix.size();
	operatorStack.push('(');
	for(int i=0;i<length;i++){
		if(infix[i] == '('){
			operatorStack.push('(');
		}
		else if(infix[i] == ')'){
			while(operatorStack.top() != '('){
				postfix+=operatorStack.top();
				operatorStack.pop();
			}
			operatorStack.pop();
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^'){
			while(operatorStack.top() != '(' && precedence[operatorStack.top()] >= precedence[infix[i]]){
				postfix+=operatorStack.top();
				operatorStack.pop();
			}
			operatorStack.push(infix[i]);
		}
		else{
			postfix += infix[i];
		}
	}
	while(operatorStack.top() != '('){
		postfix += operatorStack.top();
		operatorStack.pop();
	}
	return postfix;
}
int main(){
	string infix, postfix;
	cout<<"Enter the infix notation:\n";
	cin>>infix;
	postfix = infixToPostfix(infix);
	cout<<"The postfix notation of "<<infix<<":\n";
	cout<<postfix<<"\n";
	return 0;
}
