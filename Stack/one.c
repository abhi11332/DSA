#include<stdio.h>

// we are implementing stack using array
int s[10];  // stack ke liye Array
int top = -1; 
int size = 10;

void push(int value){

if(top==size-1){
    printf("The Stack is already Full.\n");
    return;
}    
  top++;
  s[top] = value;

}
int pop(){
   if(top==-1){
    printf("The Stack is empty.\n");
    return -1;
   }
    int poppedElement = s[top];
    top--;
    return poppedElement;
}
int peak(){
    if(top==-1){
        return -1;
    }
    return s[top];
}
int cap(){
    return top==-1?0:top+1;
}

int main(){

   push(10);
   push(20);
   push(30);
   push(40);
   push(50);
   printf("Capacity of Stack is : %d\n",cap());
   printf("Peak element is : %d\n",peak());
   printf("Popped element is : %d\n",pop());
   push(70);
   push(80);
   printf("Capacity of Stack is : %d\n",cap());
   printf("Peak element is : %d\n",peak());
   printf("Popped element is : %d\n",pop());
   printf("Popped element is : %d\n",pop());
   printf("Peak element is : %d\n",peak());
   printf("Capacity of Stack is : %d\n",cap());


    return 0;
}