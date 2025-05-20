#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    struct Node* top;
    int count;
}Stack;



void push(Stack* stack, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
}

int pop(Stack* stack){
    if(stack->top==NULL){
        printf("Stack is Empty");
        return -1;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    int data = temp->data;
    free(temp);
    stack->count--;
    return data;

}
void peak(Stack* stack){
    if(stack->top==NULL){
        printf("Stack is empty");
    }
    int data = stack->top->data;
    printf("Peak element is : %d\n",data);
}

void display(Stack* stack){
    if(stack->top==NULL){
        printf("Stack is empty");
    }
    Node* temp = stack->top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){

    Stack stack;
    stack.top = NULL;
    stack.count = 0;
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    printf("Linked list is : ");
    display(&stack);
    printf("Count : %d\n",stack.count);
    int poppedElement = pop(&stack);
    printf("Popped element is : %d\n",poppedElement);
    printf("Count : %d\n",stack.count);
    peak(&stack);
    push(&stack,5);
    push(&stack,8);
    printf("Linked list is : ");
    display(&stack);
    printf("Count : %d\n",stack.count);
     poppedElement = pop(&stack);
    printf("Popped element is : %d\n",poppedElement);
     poppedElement = pop(&stack);
    printf("Popped element is : %d\n",poppedElement);
    peak(&stack);
    printf("Count : %d\n",stack.count);
    printf("Linked list is : ");
    display(&stack);



    return 0;
}