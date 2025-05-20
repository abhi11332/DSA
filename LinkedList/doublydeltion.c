#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* insertAtTail(Node* head, int val) {
    Node* newNode = createNode(val);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* deleteAtHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }
    Node* newNode = head;
    newNode = newNode->next;
    newNode->prev = NULL;
    free(head);
    return newNode;
}

Node* deleteAtTail(Node* head) {
     if (head == NULL) {
        return NULL;
    }
    if(head->next==NULL){
        free(head);
        return NULL;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

Node* deleteAtKthPosition(Node* head,int k) {
    if (k <= 0) {
        printf("Invalid Position\n");
        return head;
    }

    if (k == 1) {
        return deleteAtHead(head);
    }

    Node* temp = head;
    int i = 1;

    while (temp != NULL && i < k) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position\n");
        return head;
    }
     
    if(temp->next!=NULL){
   temp->prev->next = temp->next;
   temp->next->prev = temp->prev;
    }else{
       temp->prev->next = NULL; 
    }

   free(temp);
   return head;
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

int main() {
    
    Node* head = NULL;

    for (int i = 1; i <= 10; i++) {
        head = insertAtTail(head, i);
    }

    printf("Original Linked List:\n");
    printNode(head);

    printf("Reversed Linked List:\n");
    reversePrintNode(head);

    
    head = deleteAtHead(head);

    
    head = deleteAtTail(head);

    
    int k;
    printf("Enter position k to Delete : ");
    scanf("%d", &k);

    head = deleteAtKthPosition(head,k);

    printf("Updated Linked List:\n");
    printNode(head);

    printf("Reversed Linked List:\n");
    reversePrintNode(head);

    return 0;
}
