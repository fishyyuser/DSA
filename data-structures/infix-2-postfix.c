#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char stack[20];//max ops in stack is 50
char postfix[50];
char infix[60];
int top = -1;

int precedence(char op);

void appendRightParenthesis(){
    int len=strlen(infix);
    for(int i=0;i<len;i++){
        if(infix[i]=='\n'){
            infix[i]=')';
            infix[i+1] = '\0';
            return;
        }
    }  
}

void removeWhiteSpace(){
    int len=strlen(infix);
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] != ' ') {
            infix[j] = infix[i];
            j++;
        }
    }
    infix[j]='\0';
}

void push(char data) {
    if (top == 19) {
        printf("\n********* Overflow: Stack is full *********\n");
        return;
    } else {
        stack[++top] = data;
    }
}


char pop() {
    if (top == -1) {
        printf("\n\n******** Underflow: Stack is empty **********\n\n");
        return -69;//sentinel value
    } else {
        int topData = stack[top];
        stack[top--] = '\0';
        return topData;
    }
}

int precedence(char op){
    switch (op)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case'^':
        return 3;
        break;
    case '(':
        return 0;
        break;
    case ')':
        return 10;
        break;
    default:
        return -1;
    }
}
bool isOperator(char ch){
    return (ch == '+'||ch =='-'||ch=='*'||ch=='/'||ch=='^'||ch=='('||ch==')');
}
bool isOp(char ch){
    return (ch == '+'||ch =='-'||ch=='*'||ch=='/'||ch=='^');
}

bool isOperand(char ch){
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
}
bool checkInfix(){
    int len = strlen(infix);
    int parenthesesBalance = 0;

    for (int i = 0; i < len; i++) {
        char currentChar = infix[i];
        if(currentChar=='\0'){
            break;
        }
        
        if(!isOperator(currentChar) && !isOperand(currentChar)&& currentChar!='\n'){
            //printf("\n1\n");
            return false;
        }
        if (currentChar == '(') {
            parenthesesBalance++;
        } else if (currentChar == ')') {
            parenthesesBalance--;
            if (parenthesesBalance < 0) {
                //printf("\n2\n");
                return false; // Unbalanced parentheses
            }
        }else if(infix[0]==')'||infix[len-1]=='('){
            //printf("\n3\n");
            return false;
        }
         else if (isOp(currentChar)) {
            if (i == 0 || i == len - 1 || isOp(infix[i - 1]) || isOp(infix[i + 1])) {
                //printf("\n4\n");
                return false; // Invalid operator placement
            }
        }else if (isOperand(currentChar)) {
            if (i > 0 && isOperand(infix[i - 1])) {
                //printf("\n5\n");
                return false; // Adjacent operands without an operator
            }
        }
    }
    return true; 
}

void convert2Postfix(char infix[]){
    int i,j;
    i=0;j=0;
    while(infix[i]!='\0'){
        
        // if operand then simply push to expression
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
            continue;
        }
        else if(isOperator(infix[i])){
            int p=precedence(infix[i]);
            if(infix[i]=='('){
                //when incoming operator is left parentheses push the incoming operator onto the stack
                push(infix[i++]);
                continue;
            }

            // if right parenthesis is found
            if(infix[i]==')'){
                while(1){
                    if(stack[top]=='('){
                        pop();
                        break;
                    }
                    else{
                        postfix[j++]=pop();
                    }
                }//end of loop
                i++;
                continue;                
            }

            if(top!=-1){
                int tosP=precedence(stack[top]);
                if(p>tosP){
                    push(infix[i++]);
                    continue;
                }
                else if (p<=tosP){
                    postfix[j++]=pop();
                }
            }

            
        }

    }
}
int main(){
    push('(');//pushing left parenthsis into the stack
    printf("Enter infix expression :");
    fgets(infix,60,stdin);
    removeWhiteSpace();
    //printf("Remove whitespaces String : %s",infix);
    bool validInfix=checkInfix();
    if(validInfix){
        appendRightParenthesis();
        printf("Normalised String : %s",infix);
        convert2Postfix(infix);
        printf("\nConverted Postfix Expression : %s",postfix);
    }
    else {
        printf("\nInvalid Infix expression");
    }
    return 0;
}