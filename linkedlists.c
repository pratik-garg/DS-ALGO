                    //PROGRAM FOR CREATING A LINKED LISTS
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node * NODE;                        //using typedef
NODE getnode();
NODE insert_front(NODE );
NODE delet_front(NODE);
void display(NODE);
NODE insert_rear(NODE);
NODE delet_rear(first);
int main()
{
    NODE first;
    first = NULL;
    printf("INSERT ELEMENT\n");
                                    //initializing as NULL POINTER
    first = insert_front(first);
    printf("INNSERET ELEMENT FORM FRONT END TWO TIMES\n");
    first = insert_front(first);
    first = insert_front(first);
    printf("displaying the elements of the linked lists\n");
    display(first);
    printf("NOW TIME TO DELETE FROM FRONT\n");
    first = delet_front(first);
    printf("displaying the elements of the linked lists\n");
    display(first);
            //PRINNTING IT IN LINKED LISTS PATTERN LIKE THIS info3->info2->info1.
    printf("INSERT ELEMENTS FORM REAR END TWO TIMES\n");
    first = insert_rear(first);
    first = insert_rear(first);
    printf("displaying the elements of the linked lists\n");
    display(first);
    printf("DELETING FROM REAR\n");
    first = delet_rear(first);
    printf("displaying the elements of the linked lists\n");
    display(first);
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
