/* Transform an Infix expression into Postfix expression(single-digit) */
#include<bits/stdc++.h>
using namespace std;

int precedence(char operand){
	if(operand == '+' || operand == '-'){
		return 1;
	}
	if(operand == '*' || operand == '/'){
		return 2;
	}
	if(operand == '^'){
		return 3;
	}
	cout<<"Operand is not valid!\n";
	exit(1);
}
int push(char stack[], int top, char value){
	stack[++top] = value;
	return top;
}
int pop(char stack[], int top){
	return --top;
}
string infixToPostfix(string infix){
	string postfix = "";
	char operatorStack[100];
	int top = -1, length = infix.size();
	top = push(operatorStack, top, '(');
	for(int i=0;i<length;i++){
		if(infix[i] == '('){
			top = push(operatorStack, top, '(');
		}
		else if(infix[i] == ')'){
			while(operatorStack[top] != '('){
				postfix+=operatorStack[top];
				top = pop(operatorStack, top);
			}
			top = pop(operatorStack, top);
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^'){
			while(operatorStack[top] != '(' && precedence(operatorStack[top]) >= precedence(infix[i])){
				postfix+=operatorStack[top];
				top = pop(operatorStack, top);
			}
			top = push(operatorStack, top, infix[i]);
		}
		else{ //operand
			postfix += infix[i];
		}
	}
	while(operatorStack[top] != '('){
		postfix += operatorStack[top];
		top = pop(operatorStack, top);
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
