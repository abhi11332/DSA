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
    int sum = 0;
    int num;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        num = temp->data;
        if(num%2==0){
            sum = sum+num;
        }
        temp = temp->next;
    }
    printf("NULL\n");
    if(sum==0){
        printf("There is No Even Number in the LinkedList.\n");
    }
    else{
        printf("Sum of Even Number is : %d.\n",sum);
    }
}

int main(){
   int count = 0;
   struct node* head = createNode(&count);
   printNode(head);

   printf("Count of The Node = %d",count);
}