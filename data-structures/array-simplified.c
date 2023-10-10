#include<stdio.h>
#include<stdlib.h>
int arr[30];
int t=-1;

void displayArray(){
    if(t==-1){
        printf("Empty Array\n");
        return;
    }
    printf("Array Elements : \n");
    for(int j=0;j<=t;j++){
        printf("\t%d",arr[j]);
    }
}
void enterElements(){
    int ele=0;
    int ind=t;
    int choice=1;
    while(1){
        printf("Do you want to add element\n1.Yes \n2.No\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
            printf("Enter the element:\n");
            scanf("%d",&ele);
            arr[++ind]=ele;
            break;        
        }
        default:
            t=ind;
            if(ind==-1){
                printf("Exiting...");
                exit(1);
            }
            return;
        }
        
    }
}
void appendElement(){
    int element;
    int ind=t;
    if(ind==30){
        printf("\n\n******** Memory Exceeded **********\nAborting Append Operation\n");
        return;
    }else{
        printf("Enter the element you want to add at the end\n");
        scanf("%d",&element);
        printf("%d",ind);
        arr[++ind]=element;
        printf("%d",ind);
        printf("\n\n%d appended Sucessfully\n",element);
        t=ind;
    }

}
void insertAt(int index){
    int len=t;
    int temp,element;
    if(len==30){
        printf("\n\n******** Memory Exceeded **********\nAborting Insert Operation\n");
        return;
    }else if(len>=index ||(len+1)==index){
        printf("Enter the element you want to add :\n");
        scanf("%d",&element);
        for(int j=len;j>=index;j--){
            arr[j+1]=arr[j];
        }
        len++;
        arr[index]=element;
        t=len;
    }
}
void insertAtBegin(){
    insertAt(0);
}
void insertAtEnd(){
    int k=t;
    k++;
    insertAt(k);
}
void deleteAt(int index){
    int len=t;
    if(t==-1){
        printf("\n\n******** Empty Array **********\n\n");
        return;
    }else if(index>t){
        printf("\n\n*********** Array Index Out of Bounds ********\n");
        return;
    }
    else{
        for(int j=index;j<len;j++){
            arr[j]=arr[j+1];
        }
        len--;
        t=len;
    }
}

void searchElement(int element){
    int len=t;
    int f,j;
    for(j=0;j<=len;j++){
        if(arr[j]==element){
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
void sortArray(){
    int len=t;
    int temp,min;
    
    for (int j=0;j<=len-1;j++){
        min=j;
        for(int k=j+1;k<=len;k++){
            if(arr[min]>arr[k]){
                min=k;
            }
            
        }
        if(min!=j){
        temp=arr[j];
        arr[j]=arr[min];
        arr[min]=temp;
        }
    }
    printf("\n\n\n\t\t************ Sorted Array ***********\n");
    displayArray();
}
//implementing insertion sort on the array
void insertionSortArray(){
    int len=t;
    int i, key, j;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("\n\n\n\t\t************ Sorted Array ***********\n");
    displayArray();
}
int main(){
    int choice,ch,index;
    printf("Array Created\n");
    enterElements();
    
    displayArray();
    while(1){
        printf("\nMENU\n1.Traverse\n2.Insert\n3.Delete\n4.Linear Search\n5.Sort using Selection Sort\n6.Sort using Insetion Sort\n7.Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        displayArray();
        break;
    case 2:{
            printf("Insert Menu\n1.Insert At Index\n2.Insert At End\n3.Insert At Begining\n");
            scanf("%d",&ch);
            switch (ch)
            {
            case 1:
                printf("Enter the Index where you want to Insert\n");
                scanf("%d",&index);
                insertAt(index);
                displayArray();
                break;
            case 2:
                insertAtEnd();
                displayArray();
                break;
            case 3:
                insertAtBegin();
                displayArray();
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
                deleteAt(index);
                displayArray();
                break;
            case 2:
                printf("Deleting End element ...\n");
                deleteAt(t);
                displayArray();
                break;
            case 3:
                printf("Deleting First element ...\n");
                deleteAt(0);
                displayArray();
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
            searchElement(index);
    }
        break;
    case 5:
        {
            printf("Array Befor Sorting\n");
            displayArray();
            sortArray();
        }
        break;
    case 6:
        {
            printf("Array Befor Sorting\n");
            displayArray();
            insertionSortArray();
        }
        break;
    case 7:
        printf("Exiting...\n");
        exit(1);
    default:
        printf("Invalid Choice!!!\n");
    }
    }
    return 0;
}