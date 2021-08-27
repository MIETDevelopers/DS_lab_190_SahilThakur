#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(){
    struct Node* ptr;
    int val;
    printf("Enter the data you want to store in the new node-> ");
    scanf("%d",&val);
    ptr = (struct Node*) malloc(sizeof(struct Node));
    if(ptr->next == NULL){
        printf("Stack Overflow");
    }
    else{
        ptr->data = val;
        ptr->next = top;
        top = ptr;
    }
}

void pop(){
    struct Node* temp;
    if(top == NULL){
        printf("No elements to pop from the list\n");
    }
    else{
        temp = top;
        top = top->next;
        printf("Deleted element is %d\n",temp->data);
        free(temp);
    }
}

void display(){
    struct Node* temp;
    if(top == NULL){
        printf("No elements to disaplay\n");
    }
    else{
        temp = top;
        printf("Elments->");
        while(temp!=NULL){
            printf("%d,",temp->data);
            temp = temp-> next;
        }
    }
}

int main(){
    int ch;
    do{
        printf("\n**Enter your choice**\n");
        printf("1. To Push\n2. To Pop\n3. To Display\n4. To Exit the program\n");
        scanf("%d",&ch);

        switch(ch)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("You have sucessfully Exited the program\n");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        };  
    }while(ch!=4);
}