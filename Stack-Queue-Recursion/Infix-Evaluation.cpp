// infix -> postfix -> evaluation (single-digit)
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
int pushInt(int stack[], int top, int value){
	stack[++top] = value;
	return top;
}
int popInt(int stack[], int top){
	return --top;
}
int pushChar(char stack[], int top, char value){
	stack[++top] = value;
	return top;
}
int popChar(char stack[], int top){
	return --top;
}
string infixToPostfix(string infix){
	string postfix = "";
	char operatorStack[100];
	int top = -1, length = infix.size();
	top = pushChar(operatorStack, top, '(');
	for(int i=0;i<length;i++){
		if(infix[i] == '('){
			top = pushChar(operatorStack, top, '(');
		}
		else if(infix[i] == ')'){
			while(operatorStack[top] != '('){
				postfix+=operatorStack[top];
				top = popChar(operatorStack, top);
			}
			top = popChar(operatorStack, top);
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^'){
			while(operatorStack[top] != '(' && precedence(operatorStack[top]) >= precedence(infix[i])){
				postfix+=operatorStack[top];
				top = popChar(operatorStack, top);
			}
			top = pushChar(operatorStack, top, infix[i]);
		}
		else{ //operand
			postfix += infix[i];
		}
	}
	while(operatorStack[top] != '('){
		postfix += operatorStack[top];
		top = popChar(operatorStack, top);
	}
	return postfix;
}
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
int postfixEvaluation(string postfix){
	int operandStack[100];
	int top = -1, operand1, operand2;
	for(int i=0; i<postfix.size(); i++){
		if(postfix[i] >= '0' && postfix[i] <= '9'){
			top = pushInt(operandStack, top, postfix[i] - '0'); //integer value of the char type digit
		}
		else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'){
			operand2 = operandStack[top];
			top = popInt(operandStack, top);
			operand1 = operandStack[top];
			top = popInt(operandStack, top);
			top = pushInt(operandStack, top, calculate(operand1, operand2, postfix[i]));
		}
		else{
			cout<<"Invalid Exprassion!\n";
			exit(1);
		}
	}
	return operandStack[top];
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
