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


Node* insertAtHead(Node* head, int val){
    if(head==NULL){
        return createNode(val);
    }
    Node* newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

Node* insertAtTail(Node* head, int val){
    if(head==NULL){
        return createNode(val);
    }
    Node* newNode = createNode(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAtKthPosition(Node* head, int val, int k){
    if(head==NULL){
        return createNode(val);
    }
    Node* newNode = createNode(val);
    int i = 1;
    Node* temp = head;
    while(i!=k-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }

   if(temp->next==NULL && k>i+1){
    printf("Invalid Position\n");
    return NULL;
   }

   newNode->next = temp->next;
    temp->next = newNode;
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

    first = insertAtHead(first,11);
     insertAtTail(first,22);
     int k;
     printf("Enter K = ");
     scanf("%d",&k);

     if(k==1){
        first = insertAtHead(first,66);
     }else{
        insertAtKthPosition(first, 78, k);
     }
     
     printNode(first);


    return 0;
}