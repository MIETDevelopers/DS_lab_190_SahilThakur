#include<stdio.h>
int stack[5],top=-1;
void push();
void pop();
void display();
void end();
int main(){
	
	int ch;
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. display\n");
	printf("4. exit\n");
	
	while(1){
		printf("\nPlease enter your choice\n");
		scanf("%d",&ch);
		switch(ch){
			
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: display();
			break;
			case 4: end();
			default:printf("Invalid choice");
			
		}
	}
}
		
	void push(){
		int item;
		if(top==5-1){
		    printf("Stack is full");
		}
		else{
			    printf("enter the number to insert in stack\n");
				scanf("%d",&item);
				top=top+1;
				stack[top]=item;
					
				}
	}
	void pop(){
		if(top==-1)
		{
			printf("Stack is empty");
		}
		else{
			printf("\npoped the element %d",stack[top]);
			top=top-1;
			}
	
		
	}
	void display()
{
		int i;
		if(top>=0)
		{
		
					printf("\nelements in the stack are\n");
					for(i=top;i>=0;i--)
					{
					printf("%d ",stack[i]);
					}
			}
			else {
				printf("Stack is totally empty");
			}
	}
