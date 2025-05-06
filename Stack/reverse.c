#include<stdio.h>
int max = 100;

void reversedArray(int arr[], int n){
    int stack[max];
    int top = -1;
    for (int i = 0; i < n; i++)
    {
        top++;
        stack[top] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = stack[top];
        top--;
    }
    
    
}

void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){

    int n;
    printf("Enter Size of an Array : ");
    scanf("%d",&n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    
    printf("Original Array: ");

    printArray(arr,n);

    reversedArray(arr,n);

    printf("Reeversed Array : ");

    printArray(arr,n);



    return 0;
}