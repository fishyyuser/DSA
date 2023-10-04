#include<stdio.h>
#include<stdlib.h>
int arr[30];

void displayArray(int *ptr,int *i){
    int ind=*i;
    if(ind==-1){
        printf("Empty Array\n");
        return;
    }
    printf("Array Elements : \n");
    for(int j=0;j<=ind;j++){
        printf("\t%d",ptr[j]);
    }
}
void enterElements(int *ptr,int *i){
    int ele=0;
    int ind=*i;
    int choice=1;
    while(1){
        printf("Do you want to add element\n1.Yes \n2.No\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
            printf("Enter the element:\n");
            scanf("%d",&ele);
            ptr[++ind]=ele;
            break;        
        }
        default:
            *i=ind;
            if(ind==-1){
                printf("Exiting...");
                exit(1);
            }
            return;
        }
        
    }
}
void appendElement(int *ptr,int *i){
    int element;
    int ind=*i;
    if(ind==30){
        printf("\n\n******** Memory Exceeded **********\nAborting Append Operation\n");
        return;
    }else{
        printf("Enter the element you want to add at the end\n");
        scanf("%d",&element);
        printf("%d",ind);
        ptr[++ind]=element;
        printf("%d",ind);
        printf("\n\n%d appended Sucessfully\n",element);
        *i=ind;
    }

}
void insertAt(int *ptr,int *i,int index){
    int len=(*i);
    int temp,element;
    if(len==30){
        printf("\n\n******** Memory Exceeded **********\nAborting Insert Operation\n");
        return;
    }else if(len>=index ||(len+1)==index){
        printf("Enter the element you want to add :\n");
        scanf("%d",&element);
        for(int j=len;j>=index;j--){
            ptr[j+1]=ptr[j];
        }
        len++;
        ptr[index]=element;
        *i=len;
    }else{
        printf("\n\n******** Index Out of Bounds **********\n\n");
    }
}
void insertAtBegin(int *ptr,int *i){
    insertAt(ptr,i,0);
}
void insertAtEnd(int *ptr,int *i){
    int k=*i;
    k++;
    insertAt(ptr,i,k);
}
void deleteAt(int *ptr,int *i,int index){
    int len=(*i);
    if((*i)==-1){
        printf("\n\n******** Empty Array **********\n\n");
        return;
    }else if((*i)<index){
        printf("\n\n******** Index Out of Bounds **********\n\n");
    }
    else{
        for(int j=index;j<len;j++){
            ptr[j]=ptr[j+1];
        }
        len--;
        *i=len;
    }
}

void searchElement(int *ptr,int *i,int element){
    int len=*i;
    int f,j;
    for(j=0;j<=len;j++){
        if(ptr[j]==element){
            f=1;
            break;
        }
    }
    if(f==1){
        printf("Element found at index %d \n",j);
    }else{
        printf("Element Not Found in Array \n");
    }
    return;
}
//implementing selection sort on the array
void sortArray(int *ptr,int *i){
    int len=*i;
    int temp,min;
    
    for (int j=0;j<=len;j++){
        min=j;
        for(int k=j+1;k<=len;k++){
            if(ptr[min]>ptr[k]){
                min=k;
            }
        }
        if(min!=j){
            temp=ptr[j];
            ptr[j]=ptr[min];
            ptr[min]=temp;
            }
    }
    printf("\n\n\n\t\t************ Sorted Array ***********\n");
    displayArray(ptr,i);
}
int main(){
    int choice,ctr,ch,index;
    ctr=-1;
    printf("Array Created\n");
    enterElements(arr,&ctr);
    
    displayArray(arr,&ctr);
    while(1){
        printf("\nMENU\n1.Traverse\n2.Insert\n3.Delete\n4.Linear Search\n5.Sort using Selection Sort\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        displayArray(arr,&ctr);
        break;
    case 2:{
            printf("Insert Menu\n1.Insert At Index\n2.Insert At End\n3.Insert At Begining\n");
            scanf("%d",&ch);
            switch (ch)
            {
            case 1:
                printf("Enter the Index where you want to Insert\n");
                scanf("%d",&index);
                insertAt(arr,&ctr,index);
                displayArray(arr,&ctr);
                break;
            case 2:
                insertAtEnd(arr,&ctr);
                displayArray(arr,&ctr);
                break;
            case 3:
                insertAtBegin(arr,&ctr);
                displayArray(arr,&ctr);
                break;
            
            default:
                printf("Invalid choice\n");
                break;
                return 0;
            }
        }
        break;
    case 3:
    {
        printf("Delete Menu\n1.Delete At Index\n2.Delete At End\n3.Delete At Begining\n");
            scanf("%d",&ch);
            switch (ch)
            {
            case 1:
                printf("Enter the Index where you want to Delete\n");
                scanf("%d",&index);
                deleteAt(arr,&ctr,index);
                displayArray(arr,&ctr);
                break;
            case 2:
                printf("Deleting End element ...\n");
                deleteAt(arr,&ctr,ctr);
                displayArray(arr,&ctr);
                break;
            case 3:
                printf("Deleting First element ...\n");
                deleteAt(arr,&ctr,0);
                displayArray(arr,&ctr);
                break;
            
            default:
                printf("Invalid choice\n");
                break;
            }
        }
        break;
    case 4:{
            printf("Enter the element you want to search :\n");
            scanf("%d",&index);
            searchElement(arr,&ctr,index);
    }
        break;
    case 5:
        {
            printf("Array Befor Sorting\n");
            displayArray(arr,&ctr);
            sortArray(arr,&ctr);
        }
        break;
    
    default:
        printf("Invalid Choice!!!\n\nExiting...");
        exit(1);
    }
    }
    return 0;
}