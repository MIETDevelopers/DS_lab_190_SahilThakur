#include<stdio.h>
#include<stdlib.h>
void insert(int [],int p);
int search(int []);
int delete(int []);
int main()
{
    int a[20];
    int choice;
    int i, n;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    printf("\nEnter %d elements in an array:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1)
	{
        printf("\nEnter 1 to insert element in array.");
        printf("\nEnter 2 to search element in array.");
        printf("\nEnter 3 to Delete element in array.");
        printf("\nEnter 4 to Exit.");
        printf("\n\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice) 
		{
            case 1:insert(a,n);
                        break;
          
            case 2:search(a);
                        break;
            case 3:delete(a);
                        break;
            case 4:exit(0);
        }
    }
    return 0;
}

void insert(int a[20] ,int p)
{ 
    int l,x,i;
    printf("\n enter location where elements is to be inserted: ");
    scanf("%d",&l);
    printf("\n enter element to be inserted: ");
    scanf("%d",&x);
    p=p+1;
    for(i=p-1;i>=l;i--)
    {
        a[i]=a[i-1];
    }

    a[l-1]=x;
    printf("\nArray After insertion is: ");
    for(i=0;i<p;i++)
    {
        printf("\t%d",a[i]);
    }
    }

int search(int a[20])
{
    int n, i, j;
    printf("Enter element to search: "); 
    scanf("%d",&j);
     
    for(i=0;i<n;++i)
        if(a[i]==j)
            break;
     
if(i<n){
        printf("Element %d found at index %d", j, i);
    }     
    else{ 
        printf("Element not found"); 
    }
    return 0;
}

int delete(int a[20])
{
    int c,k,position;
    for(k=0;a[k]!=NULL;k++)
    {
    }
    printf("\nEnter the position to delete element: ");
    scanf("%d",&position);
    if(position<=k)
    {
        for(c=position-1;c<k-1;c++)
        {
            a[c]=a[c+1];
        }
        printf("\nArray after Deletion");
        for(c=0;c<k-1;c++)
        {
            printf("\n%d",a[c]);
        }
    }
    a[c]='\0';
	return 0;
}
