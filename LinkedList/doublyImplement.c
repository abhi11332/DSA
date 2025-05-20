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

Node* insertAtHead(Node* head, int val) {
    Node* newNode = createNode(val);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
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

Node* insertAtKthPosition(Node* head, int val, int k) {
    if (k <= 0) {
        printf("Invalid Position\n");
        return head;
    }

    if (k == 1) {
        return insertAtHead(head, val);
    }

    Node* temp = head;
    int i = 1;

    while (temp != NULL && i < k - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position\n");
        return head;
    }

    Node* newNode = createNode(val);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL){
        temp->next->prev = newNode;
    }

    temp->next = newNode;

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

    
    head = insertAtHead(head, 11);

    
    head = insertAtTail(head, 22);

    
    int k;
    printf("Enter position k to insert value 78: ");
    scanf("%d", &k);

    head = insertAtKthPosition(head, 78, k);

    printf("Updated Linked List:\n");
    printNode(head);

    printf("Reversed Linked List:\n");
    reversePrintNode(head);

    return 0;
}
