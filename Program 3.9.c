#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define size_operand 20
#define size_operator 20
int top_operand=-1;
int top_operator=-1;
int top_operator_precedence=0;
int operand_stack[size_operand];
char operator_stack[size_operator];
int akhil( char expr[20],int digit,int number_int);
void push_operand(int);
void push_operator(char);
int pop_operand();
char pop_operator();
void operand_display();
void operator_display();
int calcuation();
int precedance(char);
int main()
{
	int number_int;
	char expr[20],digit;
	int choice;
	while(1){
	printf("enter 1 for  infix evaluation and 2 for exit \n");
	printf("Enter your choice \n ");
	scanf("%d",&choice);
	switch (choice){
	
	case 1 :{
	printf("Enter any expression \n ");
	scanf("%s",&expr);
	printf("Expression  = %s\n",expr);
    // int akhil(char expr[20],int digit,int number_int);
	for(int i=0;expr[i]!='\0';i++)
	{
		digit=expr[i];
		if(isalnum(digit))
		{
			number_int=digit-'0';
			push_operand(number_int); 
		}
		else
		{
			push_operator(digit);
		}

	}
			operand_display();
			operator_display();
			printf("\nexpression after evaluation = %d\n\n",calcuation());
			top_operand=-1;
	}
	break;
	case 2: exit(0);
	 default:printf("wrong \n");
	}
	}
}
void push_operand(int operand)
{
	if(top_operand==size_operand-1)
	{
		printf("Stack is Overflow \n ");
	}
	else
	{
		top_operand++;
		operand_stack[top_operand]=operand;
	}
}
void push_operator(char digit)
{
	int first_operand, second_operand,result,ans=1, precedance_op;
	char operator,operator1,demo;
	if(top_operator==size_operator-1)
	{
		printf("Stack  is Overflow \n ");
	}
	else if(top_operator==-1)
	{
		top_operator_precedence=precedance(digit);
		top_operator++;
		operator_stack[top_operator]=digit;
	}
	else		
	{
		precedance_op=precedance(digit);
		if(precedance_op>top_operator_precedence)
		{
			top_operator=top_operator+1;
			operator_stack[top_operator]=digit;
		}
		else
		{
			operator=pop_operator();
			first_operand=pop_operand();
			second_operand=pop_operand();
			if(operator=='+')
			{
				result=first_operand+second_operand;
			}
			else if(operator=='-')
			{
				result=second_operand-first_operand;
			}
			else if(operator=='*')
			{
				result=first_operand*second_operand;
			}
			else if(operator=='/')
			{
				result=second_operand/first_operand;
			}
			else if(operator=='^')
			{
				while(second_operand!=0){
					ans *=first_operand;
					--second_operand;
				}
				result=ans;
			}
			// else if(operator=='('||operator==')')
			// {
			// 	while(operator!=')'){
			// 		first_operand=pop_operand;
			// 	     demo =pop_operator;
			// 		second_operand=pop_operand;
			// 		result=second_operand demo first_operand;
			// 	}
			// }
			else
			{
				printf("Undefined Operator\n");
			}
			push_operand(result);
			top_operator=top_operator+1;
			operator_stack[top_operator]=digit;
		}	
	}	
}
int precedance(char digit)
{
		if(digit=='+' || digit=='-')
		{
			return 1;
		}
		else if(digit=='*' || digit=='/')
		{
			return 2;
		}
		else if(digit=='^')
		{
			return 3;
		}
		else if(digit=='('|| digit==')')
		{
			return 4;
		}
	return -1;	
}
int pop_operand()
{
	int operand;
	if(top_operand==-1)
	{
		printf("No operand in stack\n");
		exit(0);
	}
	else
	{
		operand=operand_stack[top_operand];
		top_operand--;
	}
	return operand;
}
char pop_operator()
{
	char operator;
	if(top_operator==-1)
	{
		printf("No operator in stack\n");
		exit(0);
	}
	else
	{
		operator=operator_stack[top_operator];
		top_operator--;
	}
	return operator;

}
void operand_display()
{
	if(top_operand==-1)
	{
		printf("No operand in Stack\n");
	}
	else
	{
		printf("Operands in the stack are\n");
		for(int i=top_operand;i>-1;i--)
		{
			printf("%d\t",operand_stack[i]);
		}
		printf("\n");
	}
}
void operator_display()
{
	if(top_operator==-1)
	{
		printf("No operator in Stack\n");
	}
	else
	{
		printf("Operator in the stack are\n");
		for(int i=top_operator;i>-1;i--)
		{
			printf("%c\t",operator_stack[i]);
		}
		printf("\n");
	}
}
int calcuation()
{
	int operand_1, operand_2,result;
	int ans=1;
	char operator;
	if(top_operand==-1)
	{
		printf("no more operator in stack");
		exit(0);
	}
	else
	{
		for (int i = top_operator; top_operator > -1; i++)
		{
			operator=pop_operator();
			operand_2=pop_operand(); 
			operand_1=pop_operand();
			if(operator=='+')
			{
				result=operand_1+operand_2;
			}
			else if(operator=='-')
			{
				result=operand_1-operand_2;
			}
			else if(operator=='*')
			{
				result=operand_1*operand_2;
			}
			else if(operator=='/')
			{
				result=operand_1/operand_2;
			}
			else if(operator=='^')
			{
				while(operand_2!=0){
					ans *=operand_1;
					--operand_2;
				}
				result=ans;
			}
			else
			{
				printf("Undefined Operator\n");
			}
			push_operand(result);
		}
	}
	return operand_stack[0];

}