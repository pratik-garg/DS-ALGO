                //PROGRAM TO FIND LENGTH OF LINKED LISTS,SORT THE LINKED LISTS
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node * NODE;
NODE getnode();
NODE insert_front(NODE );
NODE delet_front(NODE);
void display(NODE);
NODE insert_rear(NODE);
NODE delet_rear(first);
int len_of_linkedlists(NODE);
int main()
{
    NODE first = NULL;
    int length;
    first = insert_rear(first);
    first = insert_rear(first);
    first = insert_rear(first);
    first = insert_rear(first);
    first = insert_rear(first);
    length = len_of_linkedlists(first);
    printf("length of the linnked lists =%d\n",length);
    display(first);
    sort(first);
    return 0;
}
int len_of_linkedlists(NODE first)
{
    int cnt=0;
    NODE temp = first;
    if (first == NULL)
    {
        return 0;
    }

    else if (first->link==NULL)
    {
        return 1;
    }

    else
    {
       while(temp!=NULL)
       {
            cnt = cnt + 1;
            temp = temp->link;
       }
       return cnt;
    }
}
NODE getnode()                                    //THIS WILL GENERATE STRUCTURE NODE
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        exit(0);
    }
    return temp;
}
NODE insert_front(NODE first)                       //THIS WILL CONNECT AND CREATE ALL STRUCT NODES
{
    NODE temp;
    temp = getnode();
    printf("ENTER THE ELEMENT:");
    scanf("%d",&((temp)->info));           //ACCEPTINNG INFORMATION FOR EVERY NODE WHEN IT IS CALLED.
    if (first==NULL)
    {
        return temp;
    }
    (temp)->link = first;
    return temp;

}
void display(NODE first)
{
    NODE curr = first;
    if(curr == NULL)
    {
        printf("NO ELEMENTS TO DISPLAY\n");
        return ;
    }
    while(curr!=NULL)
    {
        printf("%d ",curr->info);
        curr = curr->link;
    }
    printf("\n");
}
NODE delet_front(NODE first)
{
    NODE next;
    if(first==NULL)
    {
        printf("NO ELEMENTS IN THE SINGLY LINKED LIST\n");
        return ;
    }

    else if (first->link==NULL)
    {
        printf("ELEMENT DELETED\n");
        return NULL;
    }

    else
    {
        next = first->link;
        free(first);
        return next;
    }
}
NODE insert_rear(NODE first)
{
    NODE next=getnode();
    printf("ENTER THE ELEMENT\n");
    scanf("%d",&next->info);
    next->link = NULL;
    if(first == NULL)
    {
        return next;
    }

    else if(first->link ==NULL)
    {
        first->link = next;
        return first;
    }

    else
    {
        NODE curr = first;
        while(curr->link!=NULL)
        {
            curr = curr->link;
        }
        curr->link = next;
    }
    return first;
}
NODE  delet_rear(NODE first)
{
    NODE temp=first,curr,prev;
    if(temp==NULL)
    {
        printf("NO ELEMENTS IN THE LIST\n");
        return NULL;
    }

    else if(temp->link==NULL)
    {
        free(first);
        return NULL;
    }
    else
    {
        curr = first;
        while(curr->link!=NULL)
        {
            prev=curr;
            curr = curr->link;
        }
        free(curr);
        prev->link = NULL;
        return first;
    }
}
void sort(NODE first)
{
    NODE temp=first,temp1=first,next =(temp->link);
    int  holder;
    int i=1,n=len_of_linkedlists(first),j=n;
  //  printf("length=%d\n",n);
    while(temp1->link!=NULL )
    {
        printf("i=%dmyn-1=%d\n",i,n-1);
        while(i<=n-1)
        {
            if(temp->info > next->info)
            {
                holder = temp->info;
                temp->info = next->info;
                next->info=holder;
            }
            next = next->link;
            temp = temp->link;
            display(first);
         //   printf("i=%d\n",i);
            i++;
         //   printf("i=%d\n",i);
        }
        i=1;
        n=n-1;
        next = first->link;
        temp = first;
        temp1 = temp1->link;

    }
}
