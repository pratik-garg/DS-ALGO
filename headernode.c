                    //PROGRAM ON HEADER NODE CONCEPT
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node * NODE;
void accept(int *);
NODE getnode();
void insert_front(NODE);
void insert_rear(NODE);
void delete_front(NODE);
void delete_rear(NODE);
void display(NODE);
int main()
{
    NODE head = getnode();
    head->info = 0;
    head->link = NULL;
    int ch;                                 //ch = choice
    while(1)
    {
        printf("\t\t\t*****HEADER NODE CONCEPT*****\n\n");
        printf("\t\t1.INSERT ELELMENT FROM FRONT\n");
        printf("\t\t2.INSERT ELELMENT FROM REAR\n");
        printf("\t\t3.DELETE ELEMENT FROM FRONT\n");
        printf("\t\t4.DELETE ELEMENT FORM REAR\n");
        printf("\t\t5.DISPLAY THE HEADER NODE LINKED LIST\n");
        printf("\t\t\t\tPRESS ANAY OTHER KEY TO CLOSE THE PROGRAM\n\n\n");
        printf("ENTER THE CHOICE:");
        accept(&ch);                        //scanninng the choice
        switch(ch)
        {
            case 1:insert_front(head);
                    break;

            case 2:insert_rear(head);
                    break;
            case 3:delete_front(head);
                    break;
            case 4:delete_rear(head);
                   break;
            case 5:display(head);
                    break;
            default:exit(0);
        }
    }
}
void accept(int *p)
{
    scanf("%d",p);
}
NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("NOT ENOUGH MEMORY\n");
        exit(0);
    }
    return temp;
}
void insert_front(NODE  head)
{
    int ele;
    NODE next,prev,temp = getnode();
    next = head->link;
    head->link = temp;
    temp->link = next;
    printf("ENTER THE ELEMENT:");
    accept(&ele);
    temp->info = ele;
}
void insert_rear(NODE head)
{
    int ele;
    NODE curr = head,temp = getnode();
    printf("ENTER THE ELEMENT:");
    accept(&ele);
    temp->info = ele;
    temp->link = NULL;
    while(curr->link!=NULL)
    {
        curr = curr->link;
    }
    curr->link = temp;
}
void display(NODE head)
{
    NODE curr;
    curr = head->link;
    if(curr == NULL)
    {
        printf("EMPTY LINKED LIST NOTHING TO DISPLAY\n");
        return;
    }
    printf("DISPLAYING THE LINKED LIST\n");
    do
    {
        printf("%d->",curr->info);
        curr = curr->link;
    }
    while(curr!=NULL);
    printf("\n");
}
void delete_front(NODE head)
{
    if(head->link == NULL)
    {
        printf("LINNKED LIST IS EMPTY\n");
        return;
    }
    NODE curr = head->link,next = curr->link;
    printf("ELEMENT WHICH IS DELETED=%d",curr->info);
    free(curr);
    head->link = next;
}
void delete_rear(NODE head)
{
    NODE prev= head,first=head->link,next;
    if(first == NULL)
    {
        printf("NO ELEMENTS IN THE LIST\n");
        return;
    }
    while(first->link != NULL)
    {
        prev = prev->link;
        first = first->link;
    }
    prev->link = NULL;
    printf("ELELEMNT DELETED:%d",first->info);
    free(first);
}
