#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* front = NULL;
Node* rear = NULL;
int size = 0;
void push(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(front==NULL && rear == NULL){
        front=rear=newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    size++;
    return;
}
void pop(){
    if(front==NULL && rear == NULL){
        printf("Queue is empty\n");
        return;
    }
    else{
        Node* temp = front;
        printf("Popped element is : %d\n",temp->data);
        front = front->next;
        free(temp);
    }
    size--;
    return;
}
void peek(){
    if(front==NULL && rear == NULL){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Peak elemnt is : %d\n",front->data);
    }
    return;
}
void display(){
    if(front==NULL && rear == NULL){
        printf("Queue is empty\n");
        return;
    }
    Node* temp = front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return;
}
int main(){
    push(1);
    push(2);
    push(3);
    printf("Linked List is : ");
    display();
    peek();
    printf("Size of Linked list : %d\n",size);
    pop();
    printf("Linked List is : ");
    display();
    printf("Size of Linked list : %d\n",size);
    push(7);
    push(8);
    printf("Size of Linked list : %d\n",size);
     printf("Linked List is : ");
    display();

}