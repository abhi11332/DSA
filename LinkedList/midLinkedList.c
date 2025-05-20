#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* createNode(int* count){
    struct node *start,*newNode,*temp;
    start = NULL;
    int choice = 1;
    while(choice){
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode==NULL){
            printf("Memory Allocation failed.\n");
            break;
        }
        printf("Enter Data : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        if(start==NULL){
            start = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
        printf("Would You Like To Continue? Press '1' for Continue. Press '0' for No : ");
        scanf("%d",&choice);
        (*count)++;
    }
    return start;
}
void printNode(struct node* head){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
  
}

int findMid(int k,struct node* head){
    if(head==NULL){
        printf("LinkedList is Empty");
        return -1;
    }
    if(head->next==NULL){
        return head->data;
    }
    struct node* temp = head;
    int i=1;
    while(i!=k && temp!=NULL){
        temp=temp->next;
        i++;
    }
    return temp->data;
}

int main(){
   int count = 0;
   struct node* head = createNode(&count);
   printNode(head);
   int k = (count/2)+1;
   int mid = findMid(k,head);
   printf("Mid Element is : %d\n",mid);

}