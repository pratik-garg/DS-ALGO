                    //PROGRAM FOR DECLARING THE STRUCTURE OR MEMORY OF THE N-STRUCTIRES USING CALLOC.
#include<stdio.h>
#include<stdlib.h>
struct person {
    int age;
    char gender[10];
};
typedef struct person p;

void main()
{
    p *p1;
    int n;
    accept(&n);                                // GETTING THE NUMBER OF THE PERSONS OR STRUCTURES
    p1 = (p *)calloc(n,sizeof(p));              //DECLARING MEMORY FOR THEM
    accept1(p1,n);
    display(p1,n);
}
void accept(int *n)
{
    scanf("%d",n);
}
void accept1(p *p1,int n)
{
    int i;
    printf("ENTER AGE AND GENDER OF THE PERSONS\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%s",&((p1+i)->age),&((p1+i)->gender));
    }
}
void display(p *p1,int n)
{
    int i;
    printf("DISPLAYING ALL THE INFORMATION\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n%s\n",((p1+i)->age),((p1+i)->gender));
    }
}
