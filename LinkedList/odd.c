#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;
Node* createNode(int val){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = val;
  newNode->next = newNode->prev = NULL;
  return newNode;
}

Node* createLinkedList(Node* head, int val){
        Node* newNode = createNode(val);
        if(head==NULL){
            return newNode;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return head;
}

Node* reArrange(Node* head){
        if(head->next==NULL || head==NULL){
            return head;
        }
        Node* oddHead = NULL;
        Node* oddTail = NULL;
        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* current = head;
        int index = 1;
        while(current!=NULL){
            Node* newNode = current->next;
            current->next = current->prev = NULL;
            if(index%2==1){
                if(!oddHead){
                    oddHead = oddTail = current;
                }
                else{
                    oddTail->next = current;
                    current->prev = oddTail;
                    oddTail = current;
                }
            }
            else{
                if(!evenHead){
                    evenHead = evenTail = current;
                }
                else{
                    evenTail->next = current;
                    current->prev = evenTail;
                    evenTail = current;
                }
            }
            current = newNode;
            index++;
        }
        if(oddTail){
            oddTail->next = evenHead;
        }
        if(evenHead){
            evenHead->prev = oddTail; 
        }
        return oddHead;
}
void printNode(Node* head){
    if(head==NULL){
        printf("No Linked List");
    }
    Node* temp = head;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){

    Node* head = NULL;
    for(int i=1;i<=10;i++){
        head = createLinkedList(head,i);
    }
    printf("Linked List\n");
    printNode(head);

    head = reArrange(head);
    printf("Re Arrange Linked List \n");
    printNode(head);

    return 0;
}