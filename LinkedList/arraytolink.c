#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* createNode(int val){
    struct node *newnNode;
    newnNode = (struct node*)malloc(sizeof(struct node));
    newnNode->data = val;
    newnNode->next = NULL;
    return newnNode;
}

struct node* arrayToLinkedList(int arr[],int n){
    if(n==0){
        printf("Array is Empty");
        return NULL;
    }
    struct node *start,*temp;
    start = createNode(arr[0]);
    temp = start;
    for(int i=1;i<n;i++){
        temp->next = createNode(arr[i]);
        temp = temp->next;
    }
    return start;
}

void printNode(struct node* head){
    struct node* temp = head;
    int sum = 0;
    while(temp!=NULL){
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main(){
    int n;
    printf("Enter Size Of an Array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("Elements Of Array : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    struct node* head = arrayToLinkedList(arr,n);

    printf("Linked List : \n");
    printNode(head);
}