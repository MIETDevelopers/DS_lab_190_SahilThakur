#include<stdio.h> 

#include<stdlib.h>  

int *a; 

int n, KD,i; 
int front=-1,rear=-1;
int Enqueu(); // Funtion prototype to push
int Dequeu();  // Funtion prototype to pop
void view();  // Funtion prototype to display
int main()

{
	int choice; 
    printf("Enter the size of queue: "); 
    scanf("%d",&n); 
    a = (int*)malloc(n * sizeof(int)); 
    printf("\n\n\t  MENU FOR Queue \n\n");
    while(1)
	{

        printf("\nEnter 1 to enqueue/Push element in stack.");
        printf("\nEnter 2 to dequeue/Pop element in stack.");
        printf("\nEnter 3 to view / Display element in stack.");
        printf("\nEnter 4 to Exit.");
        printf("\n\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:Enqueu();
                        break;
            case 2:Dequeu();
                        break;
            case 3:view();
                        break;
            case 4:exit(0);
            default:printf("\n\n\t*See menu Program carefully\n\n ");
        }
    }
    return 0;
}

int Enqueu() 
{
    if (rear == n -1) 
        printf("\nQueue is in  overflow\n");
    else
    {
        if(front == - 1) 
            front = 0;
        printf("\nEnter the Desired element ");
        scanf("%d",&KD);
        rear = rear + 1;  
        a[rear] = KD; 
    }
    return 0;
}

int Dequeu()
{
    if(front == -1 || front > rear) 
        printf("\nQueue is in underflow \n");
    else
    {
        printf("\nElement %d has been popped out from queue\n",a[front]);
        rear = rear - 1;
    }
    return 0;
}

void view()
{
    if (front == -1 ||front>rear) {
        printf("\nEmpty bOe !!!!!");
    }
    else{
        printf("\nElements of the queue:\n");
        for(i = front; i <= rear; ++i){
            printf("%d\n",a[i]);
        }
    }
}