#include<stdio.h>
#include<stdlib.h>                    // --> header file for dynamic memory allocation
void accept(int *,int *);              // --> for accepting array elements
void display(int *,int *);             //-->  for displaying array elements
void main()
{
    int n;
    scanf("%d",&n);
    int *p;
    p = (int *)malloc(sizeof(int)*n);       //--> memory allocated dynamically using malloc
    accept(p,&n);                           //--> accept (call)
    display(p,&n);                          //--> display (call)
                    // main function ends
}
void accept(int *p1,int *n)
{
    int i=0;
    for(i=0;i<(*n);i++)
    {
        scanf("%d",p1+i);
    }
}
void display(int *p1,int *n)
{
    int i;
    for(i=0;i<(*n);i++)
    {
        printf("%d ",*(p1+i));
    }
}
