#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void create();
void display();
void displayback();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct Node* head=NULL;
struct Node* temp;

int main()
{
    int choice;
    do
    {
        printf("\tEnter your choice\t");
        printf("\n1. To create\n2. To display\n3. To insert at the begnning\n4. To insert at the end\n5. To insert at the given position\n6. To delete at begning\n7.To delete at the end\n8. To delete at the given position\n9. To display in backward\n10. To Exit the program\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            insert_begin();
            break;

        case 4:
            insert_end();
            break;

        case 5:
            insert_pos();
            break;

        case 6:
            delete_begin();
            break;

        case 7:
            delete_end();
            break;

        case 8:
            delete_pos();
            break;

        case 9: 
            displayback();
            break;

        case 10: printf("You have sucessfully exited the pogramn\n");
                 exit(0);

        default:
            printf("Enter a valid choice\n");
        }
    } while (choice != 10);
}

void create(){
    struct Node* new;
    new = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the data you want to store in the new node-> ");
    scanf("%d",&new->data);
    new->prev = NULL;
    new->next = NULL;
    if(head==NULL){
        head=temp=new;
    }
    else{
        temp->next = new;
        new->prev = temp;
        temp = new;
    }
}

void displayback(){
    if(head == NULL){
        printf("No elements to display\n");
    }
    else{
        printf("Elements are-> ");
        while(temp!=NULL){
            printf("%d,",temp->data);
            temp = temp->prev;
        }
    }
}

void display(){
    struct Node* ptr;
    if(head == NULL){
        printf("No elements to display\n");
    }
    else{
        ptr = head;
        printf("Elements are-> ");
        while(ptr!=NULL){
            printf("%d,",ptr->data);
            ptr = ptr->next;
        }
    }
}

void insert_begin(){
    struct Node* new;
    new = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the data you want to store in the new node-> ");
    scanf("%d",&new->data);
    if(head == NULL){
        new->next = NULL;
        new->prev = NULL;
        head = new;
    }
    else{
        new->prev = NULL;
        new->next = head;
        head->prev = new;
        head = new;
    }   
}

void insert_end(){
    struct Node* new;
    new = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the data you want to store in the new node-> ");
    scanf("%d",&new->data);
    if(head == NULL){
        new->next = NULL;
        new->prev = NULL;
        head = new;
    }
    else{
        temp->next = new;
        new->prev = temp;
        new->next = NULL;
        temp = new;
    }
}

void insert_pos(){
    struct Node* new,*ptr;
    new = (struct Node*) malloc(sizeof(struct Node));
    int pos,i=0;
    printf("Enter the data you want to store in the new node-> ");
    scanf("%d",&new->data);
    printf("Enter the position you want to place node at-> ");
    scanf("%d",&pos);
    if(pos == 0){
        new->prev = NULL;
        new->next = head;
        head->prev = new;
        head = new;       
    }
    else{
        ptr = head;
        while(i!=pos-1){
            ptr = ptr->next;
            i++;
        }
        new->next = ptr->next;
        new->prev = ptr;
        ptr->next = new;
        new->next->prev = new;
    }
}

void delete_begin(){
    struct Node* ptr;
    if(head == NULL){
        printf("No elements to delete\n");
        exit(0);

    }
    if(head->next == NULL){
        ptr = head;
        head = NULL;
        printf("Deleted element is %d\n",ptr->data);
        free(ptr);
    }
    else{
        ptr = head;
        head = head->next;
        printf("Deleted element is %d\n",ptr->data);
        free(ptr);
    }
}

void delete_end(){
    struct Node* ptr;
    if(head == NULL){
        printf("No elements to delete\n");
        exit(0);
    }
    if(head->next == NULL){
        ptr = head;
        head = NULL;
        printf("Deleted element is %d\n",ptr->data);
        free(ptr);
    }
    else{
        ptr = temp;
        temp = temp->prev;
        printf("Deleted element is %d\n",ptr->data);
        free(ptr);
    }
}

void delete_pos(){
    struct Node* ptr,*ptr1;
    int pos,i=0;
    if(head == NULL){
        printf("No elements to delete\n");
        exit(0);
    }
    printf("Enter the position you want to place node at-> ");
    scanf("%d",&pos);
    if(pos == 0){
        ptr = head;
        head = head->next;
        printf("Deleted element is %d\n",ptr->data);
        free(ptr);
    }
    else{
        ptr = head->next;
        ptr1 = head;
        while(i!=pos-1){
            ptr = ptr->next;
            ptr1 = ptr1->next;
            i++;
        }
        ptr1->next = ptr->next;
        ptr->next->prev = ptr1;
        printf("Deleted element is %d\n",ptr->data);
        free(ptr);
    }
}