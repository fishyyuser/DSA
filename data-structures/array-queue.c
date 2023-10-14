#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front=-1;
int rear=-1;

void enqueue(int data){
    if(rear==(SIZE - 1)){
        printf("\n********* Overflow: Queue is Full *********\n");
        return;
    }
    else if(rear==-1 && front ==-1){
        rear++;front++;
        queue[rear]=data;
    }
    else{
        queue[++rear]=data;
    }
}
int dequeue(){
    int data;
    if(rear==-1 && front ==-1){
     printf("\n********* Underflow: Queue is Empty *********\n");
        return -69;//sentinel value
    }
    else if(rear==front){
        //only single element is present in queue
        data=queue[front];
        front=-1;rear=-1;
        return data;
    }
    else{
        data=queue[front++];
        return data;
    }
}
void displayQueue(){
    if(front==-1 && rear==-1){
        printf("\n********* Queue is Empty *********\n");
        return;
    }
    else if(rear==(SIZE - 1)){
        printf("\n********* Queue is Full *********\n");
    }
    {
        printf("\n\t\tQueue\n");
        printf("\t|---------------|\n");

        for (int i = front; i <= rear; i++) {
            if(front==rear){
                printf("\t|\t%d   \t| <-- front/rear\n", queue[front]);
                printf("\t|---------------|\n");
                break;
            }
            else if (i == front) {
                printf("\t|\t%d   \t| <-- front\n", queue[i]);
            } 
            else if (i == rear) {
                printf("\t|\t%d   \t| <-- rear\n", queue[i]);
            } 
            else {
                printf("\t|\t%d   \t|\n", queue[i]);
                }
            printf("\t|---------------|\n");}
    }
}
int main(){

    int choice, data,popVal;
    printf("Queue Created\n");
    while (1) {
        printf("\n\tQueue Operations\n1. Enqueue\n2. Dequeue\n3. Display entire Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert into queue: ");
                scanf("%d", &data);
                enqueue(data);
                displayQueue();
                break;
            case 2:{
                int deqVal=dequeue();
                if(deqVal!=-69){
                    printf("Dequeue: %d\n", deqVal);
                }                
                displayQueue();
                break;
            }
                
            case 3:
                displayQueue();
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