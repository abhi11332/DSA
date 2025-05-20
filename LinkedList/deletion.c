#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
   int data;
   struct Node* next;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}


Node* deleteAtHead(Node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    Node* temp = head;
    temp = temp->next;
    free(head);
    return temp;
}

Node* deleteAtTail(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
    Node* prev = head;
    while(temp->next!=NULL){
        prev = temp;
        temp=temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;
}

Node* deleteAtKthPosition(Node* head,  int k){
    if(head==NULL){
        return NULL;
    }
    int i = 1;
    Node* temp = head;
    Node* prev = head;
    while(i!=k && temp->next!=NULL){
        prev = temp;
        temp=temp->next;
        i++;
    }
    if(temp->next == NULL && i!=k){
        printf("Invalid Position\n");
        return NULL;
    }
    prev->next = temp->next;
    free(temp);
    return head;

}

void printNode(Node* head){
    if(head==NULL){
        printf("No Linked List Found");
        return;
    }
    Node* temp = head;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}



int main(){
    Node* first = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);

    first->next = second;
    second->next = third;
    third->next = fourth;

    printNode(first);
    printf("\n");

    // first = deleteAtHead(first);
    //  deleteAtTail(first);
     int k;
     printf("Enter K = ");
     scanf("%d",&k);

     if(k==1){
        first = deleteAtHead(first);
     }else{
        deleteAtKthPosition(first, k);
     }
     
     printNode(first);


    return 0;
}