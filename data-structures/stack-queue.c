#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* next;
    int data;
};

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
void push(struct Node **tos,int data){
    struct Node *newNode=createNode(data);
    if ((*tos)==NULL){
        *tos= newNode;
    }else {
        newNode->next = *tos;
        *tos = newNode;
    }
}
int pop(struct Node **tos){
    struct Node *temp=*tos;
    int data;
    if(temp==NULL){
        printf("\n\n******** Underflow: Stack is empty **********\n\n");
        return -69;//sentinel value
    }
    else{
        data=(*tos)->data;
        (*tos)=(*tos)->next;
        free(temp);
        return data;
    }
}
void displayStack(struct Node **tos){
    struct Node *trav=*tos;
    if(trav==NULL){
        printf("\n****** Stack is Empty *******\n");
        return;
    }
    else{
         printf("\n\t\tStack\n");
        printf("\t|---------------|\n");
        while (trav!=NULL)
        {
            if (trav == *tos) {
                printf("\t|\t%d\t| <-- top\n", trav->data);
            }
            else{
                printf("\t|---------------|\n");
                printf("\t|\t%d\t|\n", trav->data);
            }
            trav=trav->next;
        }
        printf("\t|---------------|\n");
        
    }
}
void enqueue(struct Node** front, struct Node** rear, int data){
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
int dequeue(struct Node** front, struct Node** rear){
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
void displayQ(struct Node** front, struct Node** rear){
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

int main(){

    int choice, data, choiceDS;
    struct Node *front = NULL;
    struct Node *rear = NULL;
    struct Node *tos=NULL;

   printf("\nImplementaion using Linked List \n Menu\n");
   printf("\n1.Stack\n2.Queue \n3.Exit\n");
   scanf("%d",&choiceDS);
   switch (choiceDS)
   {
    case 1:{// Implementaion  for stack

        while (1) {
        printf("\n\tStack Operations\n1. push\n2. pop\n3. Display entire stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert into stack: ");
                scanf("%d", &data);
                push(&tos,data);
                displayStack(&tos);
               
                break;

            case 2:{
                int popVal=pop(&tos);
                if(popVal!=-69){
                    printf("Popped: %d\n", popVal);
                }                
                displayStack(&tos);

                }break;

            case 3:
                displayStack(&tos);
                break;
            case 4:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid choice!!!\n");
        }
    }


        }break;
    
    case 2:{// Implementation for Queue
        
        while (1) {
        printf("\n\tQueue Operations\n1. Enqueue\n2. Dequeue\n3. Display entire Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert into queue: ");
                scanf("%d", &data);
                enqueue(&front,&rear,data);
                displayQ(&front,&rear);
                break;
            case 2:{
                int deqVal=dequeue(&front,&rear);
                if(deqVal!=-69){
                    printf("Dequeue: %d\n", deqVal);
                }                
                displayQ(&front,&rear);
                break;
                }
                
            case 3:
                displayQ(&front,&rear);
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