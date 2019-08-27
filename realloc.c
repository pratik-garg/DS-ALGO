        /*MENU DRIVEN PROGRAM FOR CREATING ARRAY MEMORY TYPE USING CALLOC AND REALLOCATING MEMORY USING REALLOC
          AND ACCESSING THE  MEMORY*/

#include<stdio.h>
#include<stdlib.h>                 // header file for calloc and realloc
void accept(int *);                 // will accept a integer value
void accept1(int *,int ,int);       // will accept the elements of the array
void dispaly(int *,int ,int);       // will display the elememts of the array
void main()
{
        int n,n1,num,*p;
        n = 3;                                         // taking initial size of the memory to be 3 blocks of integer array
        p = (int *)calloc(3,sizeof(int));               // calloc used
        n1  = n;
        while(1)
        {
            printf("\t\t\t\t****DYNAMIC MEMORY ALLOCATOR****\n\n\n");
            printf("\t\t\t1.ENTER THE ELEMENTS IN ARRAY.(CURRENT SIZE = %d)\n",n1);
            printf("\t\t\t2.DISPLAY THE EMEMENTS OF THE ARRAY\n");
            printf("\t\t\t3.REALLOCATE THE MEMORY\n\n\n");
            printf("\t\t\t\tPRESS ANY OTHER KEY TO CLOSE THE PROGRAM\n\n\n");
            accept(&num);
            switch(num)
            {
                case 1:accept1(p,n,n1);
                       break;

                case 2:display(p,n,n1);
                       break;

                case 3:accept(&n1);
                        break;

                default:exit(0);
            }
        }
}
void accept(int *p)
{
    printf("ENTER VALUE:");
    scanf("%d",p);
}
void accept1(int *p,int n,int n1)
{
    int i,j;
    if (n==n1)
    {
        j = 0;
    }

    else
    {
        j = n;
    }
    printf("ENTER THE ELEMENTS OF THE ARRAY\n");
    for (i=j;i<n1;i++)
    {
        scanf("%d",(p+i));
    }
}
void display(int *p,int n,int n1)
{
    int i;
    printf("PRINTING ALL THE ELEMENTS\n");
    for (i=0;i<n1;i++)
    {
        printf("%d ",*(p+i));
    }
    printf("\n\n\n");
}
