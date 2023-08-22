/* Find the value of an Arithmetic expression(single-digit) written in Postfix notation */
#include<bits/stdc++.h>
using namespace std;

int calculate(int operand1, int operand2, char sign){
	switch(sign){
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			return operand1 / operand2;
		case '^':
			int result = 1;
			while(operand2--){
				result *= operand1;
			}
			return result;
	}
	cout<<"Something went wrong!\n";
	exit(1);
}
int push(int stack[], int top, int value){
	stack[++top] = value;
	return top;
}
int pop(int stack[], int top){
	return --top;
}
int postfixEvaluation(string postfix){
	int operandStack[100];
	int top = -1, operand1, operand2;
	for(int i=0; i<postfix.size(); i++){
		if(postfix[i] >= '0' && postfix[i] <= '9'){
			top = push(operandStack, top, postfix[i]-'0'); //integer value of the char type digit
		}
		else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'){
			operand2 = operandStack[top];
			top = pop(operandStack, top);
			operand1 = operandStack[top];
			top = pop(operandStack, top);
			top = push(operandStack, top, calculate(operand1, operand2, postfix[i]));
		}
		else{
			cout<<"Invalid Exprassion!\n";
			exit(1);
		}
	}
	return operandStack[top];
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
