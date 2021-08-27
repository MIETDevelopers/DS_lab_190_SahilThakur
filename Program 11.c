#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(){
    struct Node* new;
    new = (struct Node*) malloc(sizeof(struct Node));
    int val;
    if(new == NULL){
        printf("Queue is full\n");
    }
    printf("Enter the data you want to enter in the queue-> ");
    scanf("%d",&val);

    if(front == 0 && rear == 0){
        front=rear=new;
        new->data = val;
        new->next = NULL;
    }
    else{
        new->data = val;
        new->next = NULL;
        rear->next = new;
        rear = new;
    }
}

void dequeue(){
    struct Node* temp;
    temp = front;
    if(front==0 && rear==0){
        printf("Queue is empty\n");
    }
    else{
        printf("Deleted element is %d",front->data);
        front = front->next;
        free(temp);
    }
}

void display(){
    struct Node* temp;
    temp = front;
    if(front==0 && rear==0){
        printf("No elements to display in the list\n");
    }
    else{
        while(temp->next == NULL){
        printf("Elements-> %d,",temp->data);
        temp = temp->next;
        }
    }
}

int main(){
        int ch;
    do{
        printf("\n**Enter your choice**\n");
        printf("1. To Enqueue\n2. To Dequeue\n3. To Display\n4. To Exit the program\n");
        scanf("%d",&ch);

        switch(ch)  
        {  
            case 1:  
            {   
                enqueue();  
                break;  
            }  
            case 2:  
            {  
                dequeue();  
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