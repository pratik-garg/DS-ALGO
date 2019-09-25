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
int main()
{
    NODE first;
    first = NULL;                                  //initializing as NULL POINTER
    first = insert_front(first);
    first = insert_front(first);
    first = insert_front(first);
    printf("%d->%d->%d\n",(first)->info,((first)->link)->info,((((first)->link)->link)->info));
            //PRINNTING IT IN LINKED LISTS PATTERN LIKE THIS info3->info2->info1.
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
