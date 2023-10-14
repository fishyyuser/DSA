#include <stdio.h>
#define SIZE 5
int stack[SIZE];
int top = -1;

void push(int data) {
    if (top == (SIZE -1)) {
        printf("\n********* Overflow: Stack is full *********\n");
        return;
    } else {
        stack[++top] = data;
    }
}

int pop() {
    if (top == -1) {
        printf("\n\n******** Underflow: Stack is empty **********\n\n");
        return -69;
    } else {
        int topData = stack[top];
        stack[top--] = 0;
        return topData;
    }
}

void displayStack() {
    if (top == -1) {
        printf("\n********* Empty Stack ********\n");
        return;
    }
    printf("\n\t\tStack\n");
    printf("\t|---------------|\n");
    for (int i = top; i >= 0; i--) {
        if (i == top) {
            printf("\t|\t%d\t| <-- top\n", stack[i]);
        } else {
            printf("\t|\t%d\t|\n", stack[i]);
        }
        printf("\t|---------------|\n");
    }
}

int main() {
    int choice, data,popVal;
    printf("Stack Created\n");
    while (1) {
        printf("\n\tStack Operations\n1. Push\n2. Pop\n3. Display entire stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert into stack: ");
                scanf("%d", &data);
                push(data);
                displayStack();
                break;
            case 2:
                popVal=pop();
                if(popVal!=-69){
                    printf("Popped: %d\n", popVal);
                }                
                displayStack();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid choice!!!\n");
        }
    }
    return 0;
}
