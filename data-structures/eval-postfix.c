#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int stack[20];
int top = -1;

int push(int);

int push(int data) {
    if (top == 19) {
        printf("\n********* Overflow: Stack is full *********\n");
        exit(1);
        return 0;
    } else {
        stack[++top] = data;
        return 1;
    }
}

int pop() {
    if (top == -1) {
        printf("\n\nInvalid Postfix Expression");
        exit(1);
    } else {
        return stack[top--];
    }
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'||ch=='^');
}
bool isDigit(char ch){
    return (ch >= '0' && ch <= '9');
}

bool checkPostfix(char postfix[]){
    int len = strlen(postfix);
    for(int i=0;i<len;i++){
        char currentChar=postfix[i];
        if(currentChar=='\0'){
            break;
        }
        if(!isOperator(currentChar) && !isDigit(currentChar)&& currentChar!='\n'&& currentChar!=' '){
            return false;
        }
        else if(i==0 && isOperator(currentChar)){
            return false;
        }
    }
    return true;
}

void evaluatePostfix(char postfix[]) {
    int i, result, op1, op2;
    i = 0;

    while (postfix[i] != '\0') {
        char ch = postfix[i];
        if (isDigit(ch)) {
            // If digit, push it onto the stack
            push(ch - '0'); 
        } 
        else if (isOperator(ch)) {
            // If operator, pop two operands and perform the operation
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    {result = op1 * op2;
                    break;}
                case '/':{
                    if (op2 != 0) {
                        result = op1 / op2;
                    } else {
                        printf("Division by zero is not allowed.\n");
                        exit(1);
                    }
                    break;}
                case '^':{
                    result=pow(op1,op2);
                    break;}

                default:printf("error");
            }
            push(result);
        }
        i++;
    }
}
bool validateStack(){
    return (top>1);
}

int main() {
    char postfix[50];

    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    evaluatePostfix(postfix);
    if(validateStack()||!checkPostfix(postfix)){
        printf("Invalid postfix expression.\n");
        return 0;
    }
    else{
        int result=pop();
        printf("Result: %d\n", result);
    }

    return 0;
}
