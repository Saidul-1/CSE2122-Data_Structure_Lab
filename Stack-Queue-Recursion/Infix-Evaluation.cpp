#include<bits/stdc++.h>
using namespace std;

map<char,int>precedence{
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
	int value;
	cout<<"Enter the infix notation:\n";
	cin>>infix;
	postfix = infixToPostfix(infix);
	cout<<"Postfix notation = "<<postfix<<"\n";
	value = postfixEvaluation(postfix);
	cout<<"The value of "<<infix<<" = "<<value<<"\n";
	return 0;
}
