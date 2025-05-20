#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int val){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = val;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

Node* convertArrayToDoublyLinkedList(int arr[], int n){
    if(n==0){
        printf("Array is Empty");
        return NULL;
    }
    Node* start;
    Node* temp;
    start = createNode(arr[0]);
    temp = start;
    for(int i=1;i<n;i++){
        Node* newNode = createNode(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return start;
}

void printNode(Node* head) {
    if (head == NULL) {
        printf("No Linked List Found\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reversePrintNode(Node* head) {
    if (head == NULL) {
        printf("No Linked List Found\n");
        return;
    }

    
    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    Node* temp = tail;
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(){

    int n;
    printf("Enter The Size of an Array : ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    Node* head = convertArrayToDoublyLinkedList(arr,n);
    printf("LinkedList\n");
    printNode(head);
    printf("Reverse LinkedList\n");
    reversePrintNode(head);


    
    return 0;
}