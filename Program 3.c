#include<stdio.h>
#include<string.h>
int top = -1;
char stack[200];
void push (char a);
void pop ();
void check();

int main ()
{
 int i ;
 char string[100];
 printf("\n enterr your expression :");
 scanf("%s",&string);
 for ( i = 0;string[i]!='\0'; i++)
    {
    if(string[i]=='(')
    { 
        push(string[i]);
    }
    else if(string[i]==')')
    {
        pop(string[i]);
    }
    }
 check();
  
  }
 void push (char a)
 {
 top++;
 stack[top]=a;
 }
    void pop()
    {
    if (top==-1){
    printf(" invalid statement \n");
    exit(0);
    }
    else
    {
    top--;
    }
    }
void check()
{
  if (top==-1)
  printf("\n the statement is correctly paranthesized");
  else
  printf("\n the statemment is wrong ");

}