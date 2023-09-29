#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to initialize an empty list with a NULL head
void initializeSLList(struct Node** head) {
    *head = NULL;
}

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the list
void insertAtHeadSL(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the tail of the list
void insertAtTailSL(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a node at a specified index in the list
void insertAtIndexSL(struct Node** head, int data, int index) {
    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }
    if (index == 0) {
        insertAtHeadSL(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    struct Node* previous = NULL;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    if (currentIndex < index) {
        printf("Invalid index.\n");
        free(newNode);
        return;
    }

    newNode->next = current;
    previous->next = newNode;
}

// Function to delete the head node
void deleteHeadSL(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the tail node
void deleteTailSL(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        // Only one node in the list
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    free(current);
    previous->next = NULL;
}

// Function to delete a node at a specified index in the list
void deleteAtIndexSL(struct Node** head, int index) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }
    if (index == 0) {
        deleteHeadSL(head);
        return;
    }
    struct Node* current = *head;
    struct Node* previous = NULL;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    if (currentIndex < index || current == NULL) {
        printf("Invalid index.\n");
        return;
    }

    previous->next = current->next;
    free(current);
}

// Function to display the linked list
void displayListSL(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Print List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                initializeSLList(&head);
                insertAtHeadSL(&head, data);
                printf("List created.\n");
                break;
            case 2:
                printf("\nInsert Menu:\n");
                printf("1. Insert at Head\n");
                printf("2. Insert at Tail\n");
                printf("3. Insert at Index\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                printf("Enter data: ");
                scanf("%d", &data);

                switch (choice) {
                    case 1:
                        insertAtHeadSL(&head, data);
                        printf("Data inserted at head.\n");
                        break;
                    case 2:
                        insertAtTailSL(&head, data);
                        printf("Data inserted at tail.\n");
                        break;
                    case 3:
                        printf("Enter index: ");
                        scanf("%d", &index);
                        insertAtIndexSL(&head, data, index);
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            case 3:
                printf("\nDelete Menu:\n");
                printf("1. Delete Head\n");
                printf("2. Delete Tail\n");
                printf("3. Delete at Index\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        deleteHeadSL(&head);
                        printf("Head node deleted.\n");
                        break;
                    case 2:
                        deleteTailSL(&head);
                        printf("Tail node deleted.\n");
                        break;
                    case 3:
                        printf("Enter index: ");
                        scanf("%d", &index);
                        deleteAtIndexSL(&head, index);
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;
            case 4:
                displayListSL(head);
                break;
            case 5:
                // Exit the program
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
