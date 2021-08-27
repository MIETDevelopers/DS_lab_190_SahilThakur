#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traverselist(struct Node* ptr){
    printf("Elements are\n");
    while(ptr!=NULL){
        printf("%d,",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtFirst(struct Node* head,int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

struct Node* insertionAtEnd(struct Node* head,int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node* insertAfterNode(struct Node* head,struct Node* prevNode,int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}


int main(){
    struct Node* head;
    struct Node* b;
    struct Node* c;

    head = (struct Node*) malloc(sizeof(struct Node));
    b = (struct Node*) malloc(sizeof(struct Node));
    c = (struct Node*) malloc(sizeof(struct Node));

    head->data = 11;
    head->next = b;

    b->data = 22;
    b->next = c;

    c->data = 33;
    c->next = NULL;

    printf("\nBefore insertion\n");

    traverselist(head);
    head = insertAtFirst(head, 99);
    printf("\nAfter insertion\n");
    traverselist(head);

    head = insertionAtEnd(head,99);
    printf("\nAfter Insertion\n");
    traverselist(head);

    head = insertAtIndex(head,99,3);
    printf("\nAfter Insertion\n");
    traverselist(head);

    head = insertAfterNode(head,b,99);
    printf("\nAfter Insertion\n");
    traverselist(head);

    return 0;
}