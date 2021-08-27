#include <stdio.h>                        
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct Node *head = NULL;

int main()
{
    int choice;
    do
    {
        printf("Enter your choice-> ");
        printf("Enter 1. to create\n2. to display\n3. to insert at the begnning\n4. to insert at the end\n5. to insert at the given position\n6. to delete at begning\n7. to delete at the end\n8. to delete at the given position\n9. to Exit the program\n");
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

        default:
            printf("Enter a valid choice\n");
        }
    } while (choice != 9);
}

void create()
{
    struct Node *temp, *ptr;
    temp = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the data you want to Enter in the node-> ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display()
{
    struct Node *ptr;
    if (head == NULL)
    {
        printf("No elements in the list\n");
        return;
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d,", ptr->data);
            printf("\n\n");
            ptr = ptr->next;
        }
    }
}

void insert_begin()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data of the node you want to create in the begnning-> ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void insert_end()
{
    struct Node *temp, *ptr;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data of the node you want to insert in the end-> ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head->next = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_pos()
{
    struct Node *ptr, *temp;
    int pos,i;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data of the node you want to insert at the given position-> ");
    scanf("%d", &temp->data);
    printf("Enter the position you want to insert your node at-> ");
    scanf("%d", &pos);
    temp->next == NULL;
    if (pos == 0)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        for (i = 0,ptr = head; i < pos-1; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Invalid Poition\n");
                return;
            }
        }
        temp->next = ptr->next; 
        ptr->next = temp;
    }
}

void delete_begin()
{
    struct Node *ptr;
    if (head == NULL)
    {
        printf("No Elements in the listn\n");
        return;
    }
    else
    {
        ptr = head;
        head = head->next;
        printf("Deleted %d from the list\n", ptr->data);
        free(ptr);
    }
}

void delete_end()
{
    struct Node *ptr, *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    else if (head->next == NULL)
    {
        ptr = head;
        head = NULL;
        printf("Deleted element is %d", ptr->data);
        free(ptr);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("Deleted element is %d", ptr->data);
        free(ptr);
    }
}

void delete_pos()
{
    struct Node *ptr, *temp;
    int pos;
    printf("Enter the position you want to delete the element at-> ");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("No elements in the list\n");
        exit(0);
    }
    if (pos == 0)
    {
        ptr = head;
        head = head->next;
        printf("Deleted element is %d", ptr->data);
        free(ptr);
    }
    else
    {
        ptr = head;
        for (int i = 0; i < pos; i++)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        printf("Deleted element is %d", ptr->data);
        free(ptr);
    }
}