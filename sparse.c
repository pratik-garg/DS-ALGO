                // PROGRAM FOR SPARSE MATRIX WITHOUT WASTING MEMORY AND PRINTING IT.
#include<stdio.h>
#include<stdlib.h>
typedef struct matrix
{
    int row;
    int col;
    int val;
}m;
void accept1(int *);
void accept_matrix(m s[],int ,int);
void display(m s[]);
void main()
{
   m s[10];
   int row,col;
   printf("ENTER THE NUMBER OF THE ROWS:");
   accept1(&row);
   printf("ENTER THE NUMBER OF THE COLUMNS:");
   accept1(&col);
   accept_matrix(s,row,col);
   display(s);

}
void accept1(int *p)
{
    scanf("%d",p);
}
void accept_matrix(m s[10],int row ,int col)
{
    int i,j,var,s_index=1;
    // enter the elements of the sparse matrix
    printf("ENTER THE ELEMENTS OF THE SPARSE MATRIX\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&var);
            if (var!=0)
            {
                s[s_index].row = i;
                s[s_index].col = j;
                s[s_index].val = var;
                s_index++;
            }
        }
    }
    s[0].row = row;
    s[0].col = col;
    s[0].val = s_index;
}
void display(m s[10])
{
    int i,j,s_index=1;
    for(i=0;i<s[0].row;i++)
    {
        for(j=0;j<s[0].col;j++)
        {
            if (s[s_index].row == i && s[s_index].col == j)
            {
                printf("%d ",s[s_index].val);
                s_index++;
            }

            else
                printf("0 ");
        }
        printf("\n");
    }
}

