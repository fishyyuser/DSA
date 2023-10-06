#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void initializeList(struct Node **head, struct Node **tail)
{
    *head = NULL;
    *tail = NULL;
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
    newNode->prev = NULL;
    return newNode;
}
void insertAtHead(struct Node **head, struct Node **tail, int data)
{   
    struct Node *temp;
    struct Node *newNode = createNode(data);
    if (*head == NULL && *tail == NULL)
    {   
        *head = newNode;
        *tail = newNode;
        newNode->prev=NULL;
        newNode->next=NULL;
    }
    else
    {   
        temp=(*head)->prev;
        (*head)->prev = newNode;
        newNode->next=*head;
        newNode->prev=temp;
    }
    // for circular linked list
    if ((*tail)->next == (*head))
    {
        (*tail)->next = newNode;
        newNode->prev = (*tail);
    }
    else
    {
        newNode->prev = NULL;
    }
    *head = newNode;
    return;
}
void insertAtTail(struct Node **head, struct Node **tail, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = (*tail)->next;
    newNode->prev = (*tail);

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        return;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
struct Node *searchNode(struct Node **head, struct Node **tail, int data)
{
    struct Node *trav;
    trav = *head;
    do
    {
        if (trav->data == data)
        {
            return trav;
        }
        else
        {
            trav = trav->next;
        }
    } while (trav != *tail);
    return NULL;
}

void insertAfter(struct Node **head, struct Node **tail, int dataS, int data)
{

    // checking if insertion at tail
    if ((*tail)->data == dataS)
    {
        insertAtTail(head, tail, data);
        return;
    }
    // for any other position
    struct Node *ptr = searchNode(head, tail, dataS);
    if (ptr == NULL)
    {
        printf("Aborting Insertion! no Node found with data %d\n", dataS);
        return;
    }
    else
    {
        struct Node *newNode = createNode(data);
        struct Node *trav = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
        newNode->next = trav;
    }
}
void deleteHead(struct Node **head, struct Node **tail)
{
    if (*head == NULL)
    {
        printf("\n\n\t\t***********List is empty *************\n");
        return;
    }
    // for single element list
    if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        printf("\n\n\t\t*********** List Deleted *******\n\n\n");
        return;
    }
    struct Node *temp = *head;
    // for circular list
    if ((*tail)->next == (*head))
    {
        (*tail)->next = (*head)->next;
        (*head)->next->prev = (*tail);
    }
    *head = (*head)->next;
    free(temp);
}

void deleteTail(struct Node **head, struct Node **tail)
{
    if (*head == NULL)
    {
        printf("\n\n\t\t***********List is empty ************\n");
        return;
    }
    // for single element list
    if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        printf("\n\n\t\t*********** List Deleted *******\n\n\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next != (*tail))
    {
        temp = temp->next;
    }
    // for circular list
    if ((*tail)->next == (*head))
    {
        temp->next = *head;
        (*head)->prev = temp;
        free(*tail);
        *tail = temp;
    }
    // linked list
    else
    {
        free(*tail);
        *tail = temp;
        (*tail)->next = NULL;
    }
}
struct Node *searchNodeDelete(struct Node **head, struct Node **tail, int data)
{
    struct Node *trav;
    trav = *head;
    do
    {
        if (trav->next->data == data)
        {
            return trav;
        }
        else
        {
            trav = trav->next;
        }
    } while (trav != *tail);
    return NULL;
}

void deleteBySearch(struct Node **head, struct Node **tail, int data)
{
    if (*head == NULL)
    {
        printf("\n\n\t\t***********List is empty ************\n");
        return;
    }
    // if data found at head
    if ((*head)->data == data)
    {
        deleteHead(head, tail);
        printf("Head Deleted\n");
        return;
    }
    // if data found at tail
    if ((*tail)->data == data)
    {
        deleteTail(head, tail);
        printf("Tail Deleted\n");
        return;
    }
    struct Node *trav = searchNodeDelete(head, tail, data);
    struct Node *temp1, *temp2;
    if (trav == NULL)
    {
        printf("\n\n\t\t*********** Data Not found **********\n");
        return;
    }
    else
    {
        temp1 = (trav->next)->next;
        temp2 = trav->next;
        free(temp2);
        trav->next = temp1;
        temp1->prev = temp1;
        return;
    }
}
void displayList(struct Node **head, struct Node **tail)
{
    if (*head == NULL)
    {
        printf("\n\n\t\t*********** List Empty !!! ***************\n");
        return;
    }
    printf("\n******* Traversing from head *******\n");
    struct Node *trav = *head;
    while (trav != *tail)
    {
        printf("\t%d \t->", trav->data);
        trav = trav->next;
    };
    if (trav == *tail)
    {
        printf("\t%d", trav->data);
    }
    return;
}
void displayRevList(struct Node **head, struct Node **tail)
{
    if (*tail == NULL)
    {
        return;
    }
    printf("\n******* Traversing from tail *******\n");
    struct Node *trav = *tail;
    while (trav != *head)
    {
        printf("\t%d \t->", trav->data);
        trav = trav->prev;
    };
    if (trav == *head)
    {
        printf("\t%d", trav->data);
    }
    return;
}

int main()
{

    struct Node *head = NULL;
    struct Node *tail = NULL;
    int choice, data, temp, a;
    data=0;

    printf("Doubly Linked List\n");
    printf("1.Doubly Linked List\n");
    printf("2.Doubly Circular Linked List\n");
    printf("3.Exit\nEnter your choice : \n");

    int ch1, ch2;
    scanf("%d", &ch1);
    switch (ch1)
    {
    case 1:
    {
        while (1)
        {
            printf("\nMenu:\n");
            printf("1. Create List\n");
            printf("2. Insert\n");
            printf("3. Delete\n");
            printf("4. Traverse List\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
            {
                initializeList(&head, &tail);
                printf("List created.\n");
                printf("Enter head data: ");
                scanf("%d", &data);
                insertAtHead(&head, &tail, data);
                displayList(&head, &tail);
                break;
            }
            case 2:
            {
                if (head == NULL)
                {
                    printf("\n\t\t********* First Create the list *********\n");
                    break;
                }

                printf("Enter data that you want to insert: \n");
                scanf("%d", &data);
                printf("\nInsert Menu:\n");
                printf("1. Insert at Head\n");
                printf("2. Insert at Tail\n");
                printf("3. Insert after value\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    insertAtHead(&head, &tail, data);
                    printf("Data inserted at head.\n");
                    displayList(&head, &tail);
                    break;
                case 2:
                    insertAtTail(&head, &tail, data);
                    printf("Data inserted at tail.\n");
                    displayList(&head, &tail);
                    break;
                case 3:
                    printf("Enter the value that you want to search\n");
                    scanf("%d", &a);
                    insertAfter(&head, &tail, a, data);
                    displayList(&head, &tail);
                    break;

                default:
                    printf("Invalid choice.\n");
                    break;
                }
                break;
            }
            case 3:
            {
                if (head == NULL)
                {
                    printf("\n\t\t********* Cannot delete Empty List ********\n");
                    break;
                }
                printf("\nDelete Menu:\n");
                printf("1. Delete Head\n");
                printf("2. Delete Tail\n");
                printf("3. Delete by search\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    deleteHead(&head, &tail);
                    displayList(&head, &tail);
                    break;
                case 2:
                    deleteTail(&head, &tail);
                    displayList(&head, &tail);
                    break;
                case 3:
                    printf("Enter the element you want to delete: \n");
                    scanf("%d", &temp);
                    deleteBySearch(&head, &tail, temp);
                    displayList(&head, &tail);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
                }
                break;
            }
            case 4:
                displayList(&head, &tail);
                displayRevList(&head,&tail);
                break;
            case 5:
                printf("\nExiting...\n");
                exit(1);
                break;
            default:
                printf("Invalid choice.\n");
                break;
            }
        }
        break;
    }
    case 2:
    {
        while (1)
        {
            printf("\nMenu:\n");
            printf("1. Create List\n");
            printf("2. Insert\n");
            printf("3. Delete\n");
            printf("4. Traverse List\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
            {
                initializeList(&head, &tail);
                printf("List created.\n");
                printf("Enter head data: ");
                scanf("%d", &data);
                insertAtHead(&head, &tail, data);
                tail->next = head;
                displayList(&head, &tail);
                break;
            }
            case 2:
            {
                if (head == NULL)
                {
                    printf("\n\t\t********* First Create the list *********\n");
                    break;
                }

                printf("Enter data that you want to insert: \n");
                scanf("%d", &data);
                printf("\nInsert Menu:\n");
                printf("1. Insert at Head\n");
                printf("2. Insert at Tail\n");
                printf("3. Insert after value\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    insertAtHead(&head, &tail, data);
                    printf("Data inserted at head.\n");
                    displayList(&head, &tail);
                    break;
                case 2:
                    insertAtTail(&head, &tail, data);
                    printf("Data inserted at tail.\n");
                    displayList(&head, &tail);
                    break;
                case 3:
                    printf("Enter the value that you want to search\n");
                    scanf("%d", &a);
                    insertAfter(&head, &tail, a, data);
                    displayList(&head, &tail);
                    break;

                default:
                    printf("Invalid choice.\n");
                    break;
                }
                break;
            }
            case 3:
            {
                if (head == NULL)
                {
                    printf("\n\t\t********* Cannot delete Empty List ********\n");
                    break;
                }
                printf("\nDelete Menu:\n");
                printf("1. Delete Head\n");
                printf("2. Delete Tail\n");
                printf("3. Delete by search\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    deleteHead(&head, &tail);
                    displayList(&head, &tail);
                    break;
                case 2:
                    deleteTail(&head, &tail);
                    displayList(&head, &tail);
                    break;
                case 3:
                    printf("Enter the element you want to delete: \n");
                    scanf("%d", &temp);
                    deleteBySearch(&head, &tail, temp);
                    displayList(&head, &tail);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
                }
                break;
            }
            case 4:
                displayList(&head, &tail);
                displayRevList(&head,&tail);
                break;
            case 5:
                printf("Exiting...\n");
                exit(1);
                break;
            default:
                printf("Invalid choice.\n");
            }
        }
    }
    default:
        printf("Exiting...\n");
        return 0;
    }
    return 0;
}