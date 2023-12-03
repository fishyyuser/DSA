#include <stdio.h>
#include <stdlib.h>

void traverse(int **arr,int rows,int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf(" %d",arr[i][j]);
        }
        printf("\n");
    }

}
void sparsify(int **arr, int rows, int cols, int count)
{
    
    int n = count + 1;
    int **array;
    array = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        array[i] = (int *)malloc(3 * sizeof(int));
    }
    array[0][0]=rows;
    array[0][1]=cols;
    array[0][2]=count;
    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != 0)
            {
                array[k][0]=i;
                array[k][1]=j;
                array[k][2]=arr[i][j];
                k++;
            }
        }
    }
    printf(" \nSparse Matrix :\n");
    traverse(array,n,3);
}
void createMatrix(int **arr,int rows,int cols){
    int count = 0;

    printf("Enter %d elements: ",rows*cols);
    arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0)
                count++;
        }
    }
    printf("\n 2D Matrix :\n");
    traverse(arr,rows,cols);

    //if the number of values if more than 25% of rows*column the discard
    if (count > (0.25 * (rows * cols)))
        printf("\nMatrix is densely populated and Unfit for creating Sparse Matrix");
    else
    {
        sparsify(arr, rows, cols, count);
    }
}
int main()
{
    int **arr,rows,cols;
    printf("Enter the number of rows: ");
    scanf(" %d", &rows);
    printf("Enter the number of columns: ");
    scanf(" %d", &cols);
    printf("\n");
    createMatrix(arr,rows,cols);
    
    

    return 0;
}