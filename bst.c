    //preorder,postorder and inorder using recursive appproch
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *NODE;
NODE getnode();
NODE insert(NODE);
void preorder(NODE);
void inorder(NODE);
void postorder(NODE);
NODE deletion(NODE);
int main()
{
    int ch;
    NODE root=NULL;
    while(1)
    {

        printf("\n\n\n\t\t\t\tTREE OPERATIONS\n");
        printf("1.INSERT\n2.DELETE\n3.PREORDER\n4.POSTORDER\n5.INORDER\n");
        printf("PRESS ANY OTHER KEY TO CLOSE THE PROGRAM\n");
        printf("ENTER THE KEY:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:system("clear");
                    root = insert(root);
                    break;
            case 2:system("clear");
                    root = deletion(root);
                    break;
            case 3:system("clear");
                    printf("PREORDER= ");
                    preorder(root);//using recursive approach
                    break;
            case 4:system("clear");
                    printf("POSTORDER= ");
                    postorder(root);
                    break;
            case 5:system("clear");
                    printf("INORDER= ");
                    inorder(root);
                    break;
            default:exit(0);

        }
    }
}
NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("MEMORY NOT ALLOCATED\n");
        exit(0);
    }
    return temp;
}
NODE insert(NODE root)
{

    int info;
    NODE cur,prev,temp = getnode();
    cur = root;
    prev = NULL;
    printf("ENTER THE INFORMATION:");
    scanf("%d",&info);
    temp->data = info;
    temp->rlink = NULL;
    temp->llink = NULL;
    if(root == NULL)
    {
        return temp;
    }
    else
    {
        while(cur!=NULL)
        {
            prev = cur;
            if(cur->data>info)
            {
                cur=cur->llink;
            }
            else
            {
                cur = cur->rlink;
            }
        }
        if(prev->data>info)
        {
            prev->llink = temp;
            return root;
        }
        else
        {
            prev->rlink = temp;
            return root;
        }
    }
}
void preorder(NODE root)
{
    if(root == NULL)
    {
        return ;
    }
    printf("%d ",root->data);
    preorder(root->llink);
    preorder(root->rlink);
}
void inorder(NODE root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->llink);
    printf("%d ",root->data);
    inorder(root->rlink);
}
void postorder(NODE root)
{
    if(root ==NULL)
        return ;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ",root->data);
}
NODE deletion(NODE root)
{
    int key;
    printf("ENTER THE KEY YOU WANT TO DELETE:");
    scanf("%d",&key);
    if(root==NULL)
    {
        printf("NO BINARY SEARCH TREE EXIST!!\n");
        return NULL;
    }

    NODE suc,next,parent = NULL;
    NODE cur = root;
    while(cur!=NULL)
    {
        if(cur->data==key)
            break;
        parent = cur;
        if(cur->data>key)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if(cur==NULL)
    {
        printf("ELEMENT NOT FOUND!!!\n");
        return root;
    }
    if(cur->rlink == NULL)
    {
        next = cur->llink;
    }
    else if(cur->llink == NULL)
    {
        next = cur->rlink;
    }
    else
    {
        suc = cur->rlink;
        while(suc->llink!=NULL)
        {
            suc = suc->llink;
        }
        suc->llink = cur->llink;
        next = cur->rlink;
    }
    if(parent==NULL)
    {
        free(cur);
        return next;
    }
    if(parent->llink==cur)
    {
        parent->llink = next;
    }
    else
    {
        parent->rlink = next;
    }
    free(cur);
    return root;

}
