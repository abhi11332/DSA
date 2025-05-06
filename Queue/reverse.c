#include<stdio.h>


int start = -1;
int end = -1;
int noe = 0;
int queue[100];

void push(int val, int k){
    if(noe==k){
        printf("The Queue is full");
        return;
    }
    if(noe==0){
        start = 0;
        end = 0;
        queue[end] = val;
        noe++;
        return;
    }
   end = (end+1)%k;
   queue[end] = val;
   noe++;
   return;
}

int pop(int k){
    if(noe==0){
        return -1;
    }
    if(noe==1){
        int poppedElement = queue[start];
        start = -1;
        end = -1;
        noe--;
        return poppedElement;
    }
    int poppedElement = queue[start];
    start = (start+1)%k;
    noe--;
    return poppedElement;
}



void reversedArray(int arr[], int k){
    
  
    for(int i=k-1;i>=0;i--){
        int val = arr[i];
        push(val,k);
    }
  

    for(int i=0;i<k;i++){
        arr[i] = pop(k);
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

    int k;
    printf("Enter Your element position where you want to reverse : ");
    scanf("%d",&k);

    if (k>n || k<=0)
    {
        printf("Enter The valid Position.\n");
    }
    else{
        reversedArray(arr,k);

        printf("Reeversed Array : ");

        printArray(arr,n);
    }
    

    

    
}