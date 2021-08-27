#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct Node* head=NULL;
struct Node* tail=NULL;

int main()
{
    int choice;
    do
    {
        printf("\tEnter your choice\t");
        printf("\n1. To create\n2. To display\n3. To insert at the begnning\n4. To insert at the end\n5. To insert at the given position\n6. To delete at begning\n7.To delete at the end\n8. To delete at the given position\n9.To Exit the program\n");
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

        case 9: printf("You have sucessfully exited the pogramn\n");
                 exit(0);

        default:
            printf("Enter a valid choice\n");
        }
    } while (choice != 10);
}

void create(){
    struct Node* new;
    new = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the value you want to store in the new node-> ");
    scanf("%d",&new->data);
    new->next=head;
    if(head==NULL){
        head=tail=new;
    }
    else{
        tail->next=new;
        tail=new;
    }
}

void display(){
    struct Node* ptr;
    if(head==NULL){
        printf("No element to display");
        exit(0);
    }
    else{
        ptr=head;
        while(ptr->next!=head){
            printf("%d,",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
}

void insert_begin(){
    struct Node* new;
    new = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the value you want to enter in your new node-> ");
    scanf("%d",&new->data);
    new->next=head;
    if(head==NULL){
        head=tail=new;
    }
    else{
        head=new;
    }
}

void insert_end(){
    struct Node* new;
    new = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the new value you want to enter in the new node-> ");
    scanf("%d",new->data);
    new->next=head;
    if(head==NULL){
        head=tail=new;
    }
    else{
        tail->next=new;
        tail=new;
    }
}

void insert_pos(){
    struct Node* new,*ptr;
    new = (struct Node*) malloc(sizeof(struct Node));
    int pos,i=0;
    printf("Enter the valu of your new node-> ");
    scanf("%d",&new->data);
    printf("Enter the position you want to enter your new node-> ");
    scanf("%d",&pos);
    if(pos==0){
        new->next=head;
        head=new;
    }
    else{
        ptr=head;
        while(i!=pos-1){
            ptr=ptr->next;
        }
        new->next=ptr->next;
        ptr->next=new;
    }
}

void delete_begin(){
    struct Node* ptr;
    if(head==NULL){
        printf("No elements to delete from the list\n");
    }
    else if(head->next==NULL){
        ptr=head;
        head=NULL;
        printf("Deleted %d",ptr->data);
        free(ptr);
    }
    else{
        ptr=head;
        tail->next = head->next;
        head = head->next;
        printf("Deleted %d",ptr->data);
        free(ptr);
    }
}

void delete_end(){
    struct Node* ptr,*tpr;
    if(head==NULL){
        printf("No elements to delete from the list\n");
    }
    else if(head->next==NULL){
        ptr=head;
        head=NULL;
        printf("Deleted %d",ptr->data);
        free(ptr);
    }
    else{
        ptr=head;
        tpr=head->next;
        while(tpr->next!=head){
            tpr=tpr->next;
            ptr=ptr->next;
        }
        ptr->next = tpr->next;
        tail=ptr;
        printf("Deleted %d",tpr->data);
        free(tpr);
    }
}

void delete_pos(){
    struct Node* ptr;
    struct Node* tpr;
    int pos,i;
    printf("Enter the position at which you want to delete your node-> ");
    scanf("%d",pos);
    if(head==NULL){
        printf("No elements to delete from the list\n");
    }
    else if(pos==0){
        ptr=head;
        tail->next = head->next;
        head = head->next;
        printf("Deleted %d",ptr->data);
        free(ptr);
    }
    else{
        ptr=head;
        tpr=head->next;
        while(i<pos-1){
            ptr=ptr->next;
            tpr=tpr->next;
        }
        ptr->next=tpr->next;
        printf("Deleted %d",tpr->data);
        free(tpr);
    }
}