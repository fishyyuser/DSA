#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Incorrect Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right= NULL;

    return newNode;
}


void insert(int data,struct Node **root){
    if((*root)==NULL){
        (*root)=createNode(data);
        return;
    }
    if((*root)->data>data){
        insert(data,&(*root)->left);
    }
    else if((*root)->data<=data){
        insert(data,&(*root)->right);
    }

}

struct Node* searchNode(int data,struct Node *root){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        return root;
    }
    if(data<root->data){
        return searchNode(data,root->left);
    }
    else if(data>root->data){
        return searchNode(data,root->right);
    }
}

struct Node* findSmallest(struct Node *root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return root;
    }
    return findSmallest(root->left);
}

struct Node* findLargest(struct Node *root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return root;
    }
    return findLargest(root->right);
}

void delete(int data, struct Node **root){
    struct Node * search= searchNode(data,*root);
    if(search==NULL){
        printf("\n************** Element does not exist in the tree ***************\n");
        return;
    }
    else{
        if(search->left==NULL && search->right==NULL){
            free(search);
            printf("Element deleted\n");
        }
        struct Node *trav;
        //left NULL right not null->find inorder successor
        if(search->left==NULL && search->right!=NULL){
            trav=findSmallest(search->right);
        }
        //right NULL left not null->find inorder predecessor
        else if(search->left!=NULL && search->right==NULL){
            trav=findLargest(search->left);
        }
        //either
        else if(search->left!=NULL && search->right!=NULL){
            trav=findSmallest(search->left);
        }
        
        //swap
        int temp=trav->data;
        trav->data=search->data;
        search->data=temp;
        free(trav);        
    }
}
void preOrder(struct Node *root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root){
    if(root==NULL){
        return;
    }
    
    inOrder(root->left);
    printf("%d\t",root->data);
    inOrder(root->right);
}

void postOrder(struct Node *root){
    if(root==NULL){
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\t",root->data);
}

int main(){
    int ch;
    struct Node *root=NULL;
    int data;

    

    while(1){
        printf("\n\nBinary Search Tree Operations \n");
        printf("1. Create BST \n");
        printf("2. Insert in BST \n");
        printf("3. Search in BST \n");
        printf("4. Delete in BST \n");
        printf("5. PreOrder Traversal\n");
        printf("6. InOrder Traversal\n");
        printf("7. PostOrder Traversal\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:{
                printf("Enter Root element: ");
                scanf("%d",&data);
                insert(data,&root);
                break;
                }
            case 2:{
                if(root==NULL){
                    printf("\n************ First create BST **************\n\n");
                    break;
                }
                ch=1;
                while(ch==1){
                    printf("Enter element: ");
                scanf("%d",&data);
                insert(data,&root);
                printf("Do you want to enter another element  Press 1 :\n");
                scanf("%d",&ch);
                }
                break;
            }
         
            case 3:{
                printf("Enter the element you want to search :");
                scanf("%d",&data);
                struct Node *trav=searchNode(data,root);
                if(trav==NULL){
                    printf("\n*************** Element does not exist in tree ***************\n");
                }
                else {
                    printf("Element found\n");
                }
                break;
            }
            case 4:{
                printf("Enter the element you want to delete :");
                scanf("%d",&data);
                delete(data,&root);
                break;
            }
            case 5:{
                printf("\nPreorder Traversal :\n");
                preOrder(root);
                break;
            }
            case 6:{
                printf("Inorder Traversal :\n");
                inOrder(root);
                break;
            }
            case 7:{
                printf("Postorder Traversal :\n");
                postOrder(root);
                break;
            }
            case 8:{
                exit(1);
                break;
            }
            default:printf("Invalid Choice\n");
        }
    }
    return 0;
}