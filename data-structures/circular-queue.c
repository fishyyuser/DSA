#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int front=-1;
int rear=-1;
struct Node{
    struct Node* next;
    int data;
};

void initializeList(struct Node **front, struct Node **rear)
{
    *front = NULL;
    *rear = NULL;
}
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Incorrect Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void enqueueC(struct Node** front, struct Node** rear, int data){
    struct Node *newNode=createNode(data);
    struct Node *temp;

    if(*front==NULL){
        *front=newNode;
        *rear=newNode;
        newNode->next=*rear;
        return;
    }
    else{
        temp=(*rear)->next;
        (*rear)->next=newNode;
        newNode->next=temp;
        *rear=newNode;
        }

}
int dequeueC(struct Node** front, struct Node** rear){
    struct Node* temp=*front;
    int dt;
    if (*front == NULL) {
        printf("\n\n\t\t***********Underflow: Queue is empty *************\n");
        return -69;//sentinel value
    }
    //for single element list
    if(*front==*rear){
        dt=(*front)->data;
        free(*front);
        *front=NULL;
        *rear=NULL;
        return dt;
    }
    
    else{
        (*rear)->next=(*front)->next;
        dt=temp->data;
    }
    *front = (*front)->next;
    free(temp);
    return dt;
}
void displayC(struct Node** front, struct Node** rear){
    if(*front==NULL){
        printf("\n\n\t\t*********** Queue Empty !!! ***************\n");
        return;
    }
    printf("\n\t\tQueue\n");
    printf("\t|---------------|\n");
    struct Node *trav=*front;
    if (*front==*rear) {
            printf("\t|\t%d   \t| <-- front/rear\n", trav->data);
            printf("\t|---------------|\n");
            return;
        }
    while(trav!=*rear){
        
        if (trav == *front) {
            printf("\t|\t%d   \t| <-- front\n", trav->data);
            printf("\t|---------------|\n");
        }
        else{
            printf("\t|\t%d   \t|\n", trav->data);
            printf("\t|---------------|\n");
        }
        trav=trav->next;
    };
    if (trav == *rear) {
            printf("\t|\t%d   \t| <-- rear\n", trav->data);
        }
    printf("\t|---------------|\n");
    return;
}

void enqueue(int data){
    if(((rear + 1) % SIZE)==front){
        printf("\n********* Overflow: Queue is Full *********\n");
        return;
    }
    else if(rear==-1 && front ==-1){
        rear++;front++;
        queue[rear]=data;
    }
    else{
        rear=++rear%SIZE;
        queue[rear]=data;
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
        data=queue[front];
        front=(front+1)%SIZE;
        return data;
    }
}
void displayQueue() {
    if (front == -1 && rear == -1) {
        printf("\n********* Queue is Empty *********\n");
        return;
    }

    int i = front;
    printf("\n\t\tQueue\n");
    printf("\t|---------------|\n");

    while (1) {
        if (i == front && i == rear) {
            printf("\t|\t%d   \t| <-- front/rear\n", queue[i]);
        } else if (i == front) {
            printf("\t|\t%d   \t| <-- front\n", queue[i]);
            printf("\t|---------------|\n");
        } else if (i == rear) {
            printf("\t|\t%d   \t| <-- rear\n", queue[i]);
            
        } else {
            printf("\t|\t%d   \t|\n", queue[i]);
            printf("\t|---------------|\n");
        }

        i = (i + 1) % SIZE;  // Move to the next position

        if (i == (rear + 1) % SIZE) {
            break;
        }
    }

    printf("\t|---------------|\n");
}

int main(){

    int choice, data, choiceDS;
    struct Node *front = NULL;
    struct Node *rear = NULL;

   printf("\nSelect the DS for Implementaion of Circular Queue \n Menu\n");
   printf("\n1.Array\n2.Circular Linked List\n3.Exit\n");
   scanf("%d",&choiceDS);
   switch (choiceDS)
   {
    case 1:{// for Implementaion using array
        
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


        }break;
    
    case 2:{// for Implementaion using Circular Linked List
        
        while (1) {
        printf("\n\tQueue Operations\n1. Enqueue\n2. Dequeue\n3. Display entire Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert into queue: ");
                scanf("%d", &data);
                enqueueC(&front,&rear,data);
                displayC(&front,&rear);
                break;
            case 2:{
                int deqVal=dequeueC(&front,&rear);
                if(deqVal!=-69){
                    printf("Dequeue: %d\n", deqVal);
                }                
                displayC(&front,&rear);
                break;
                }
                
            case 3:
                displayC(&front,&rear);
                break;
            case 4:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid choice!!!\n");
            }
        }
        }break;

    case 3:{
        printf("Exiting...");
        exit(1);
        }break;
   
   default:{
        printf("Invalid Choice\nExiting...");
        exit(1);
   }
   }


    return 0;
}