#include<stdio.h>

int arr[10];
int noe = 0;
int start = -1;
int end = -1;
int size = 10;

void push(int val){
    if(noe==size){
        printf("The Queue is full.\n");
        return;
    }
    if (noe==0)
    {
        start=0;
        end=0;
        arr[end] = val;
        noe = 1;
        return;
    }
    end = (end+1)%size;
    arr[end] = val;
    noe++;
    return;
    
}

int pop(){
    if(noe==0){
        return -1;
    }
    if(noe==1){
        int poppedElement = arr[start];
        start = -1;
        end = -1;
        return poppedElement;
    }
    int poppedElement = arr[start];
    start = (start+1)%size;
    noe--;
    return poppedElement;
}
int peak(){
    if(noe==0){
        return -1;
    }
    return arr[start];
}
int cap(){
    if (noe==0)
    {
        return -1;
    }
    return noe;
    
}

int main(){
  push(10);
  push(20);
  push(30);
  push(40);
  printf("Capacity of Queue is : %d\n",cap());
  printf("Popped Element is : %d\n",pop());
  printf("Peak element is : %d\n",peak());
  push(70);
  push(50);
  printf("Capacity of Queue is : %d\n",cap());
  printf("Peak element is : %d\n",peak());
  printf("Popped Element is : %d\n",pop());
  printf("Popped Element is : %d\n",pop());
  printf("Capacity of Queue is : %d\n",cap());
  printf("Peak element is : %d\n",peak());
  return 0;
}