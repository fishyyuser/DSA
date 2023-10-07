#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Incorrect Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void initializeList(struct Node** head,struct Node** tail){
    struct Node *temp=createNode(0);
    *head=temp;
    for(int i=1;i<5;i++){
        struct Node *newNode=createNode(i*5);
        temp->next=newNode;
        temp=newNode;
    }
    *tail=temp;
    
}

void displayList(struct Node** head, struct Node** tail){
    if(*head==NULL){
        printf("\n\n\t\t*********** List Empty !!! ***************\n");
        return;
    }
    struct Node *trav=*head;
    while(trav!=*tail){
        printf("\t%d \t->",trav->data);
        trav=trav->next;
    };
    if(trav==*tail){
        printf("\t%d",trav->data);
    }
    return;
}

void revList(struct Node** head, struct Node** tail){
    struct Node *prev=NULL;
    struct Node *current=*head;
    struct Node *nxt=current->next;
  
    do{
        current->next=prev;
        prev=current;
        current=nxt;
        if(nxt->next!=NULL){
            nxt=nxt->next;
        }        
    }while(prev!=*tail);
    
    //swapping head and tail pointers
    prev=*head;
    *head=*tail;
    *tail=prev;
    
    return;

}
void recursiveReverse(struct Node* curr, struct Node** head, struct Node** tail) {
    if (curr == NULL) {
        return;
    }
    struct Node *nxtNode=curr->next;
    
    if (nxtNode == NULL) {
        *head = curr; // Update the head when we reach the end of the list
        return;
    }

    recursiveReverse(nxtNode, head, tail);
    nxtNode->next=curr;
    *tail = curr;
}
void swap(struct Node **head,struct Node **tail){
    struct Node *temp=*head;
    *head=*tail;
    *tail=temp;
}



int main(){

    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    initializeList(&head, &tail);
    printf("List created.\n");
    displayList(&head,&tail);
    
    //iterative function
    //revList(&head,&tail);
    
    //recursive function
    recursiveReverse(head, &head, &tail);

    printf("\n************** Printing Reverse of List **********\n");
    displayList(&head,&tail);

    
   return 0;
}