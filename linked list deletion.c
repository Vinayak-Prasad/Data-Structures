#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void create();
void display();
void delete_beg();
void delete_end();
void delete_pos();

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node;
node *start=NULL;

void main()
{
    int ch,ch1;
    while(1)
    {
        printf("1.Create 2.Delete 3.Display 4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            printf("Delete at 1.Beginning 2.At any position 3.End\n");
            scanf("%d",&ch1);
            if(ch1==1)
                delete_beg();
            else if(ch1==2)
                delete_pos();
            else if (ch1==3)
                delete_end();
            else
                printf("Invalid choice\n");

            break;

        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice\n");
        }
    }
}

void create()
{
    int c;
    node *new,*curr;
    start=(node *) malloc(sizeof(node));
    curr=start;
    printf("Enter element\n");
    scanf("%d",&start->data);
    while(1)
    {
        printf("Do you want to add another element(1 for Yes / 0 for No)\n");
        scanf("%d",&c);
        if(c==1)
        {
            new=(node *) malloc(sizeof(node));
            printf("Enter element\n");
            scanf("%d",&new->data);
            curr->link = new;
            curr=new;
        }
        else
        {
            curr->link=NULL;
            break;
        }
    }
}

void display()
{
    node *temp;
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    temp=start;
    printf("Elements:\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->link;
    }
}

void delete_beg()
{
    node *temp;
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    temp=start;
    printf("Deleted element: %d\n",start->data);
    start=start->link;
    free(temp);
}

void delete_end()
{
    node *next, *prev;
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    if(start->link == NULL)
    {
        printf("%d",start->data);
        free(start);
        start=NULL;
        return;
    }
    prev=start;
    next=prev->link;
    while(next->link!=NULL)
    {
        prev=next;
        next=next->link;
    }
    printf("Deleted element: %d\n",next->data);
    prev->link=NULL;
    free(next);
}

void delete_pos()
{
    node *next, *prev, *temp;
    int ele;
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("Enter element to be deleted:\n");
    scanf("%d",&ele);
    if(start->data == ele)
    {
        temp=start;
        start=start->link;
        free(temp);
        printf("Element deleted\n");
        return;
    }
    prev=start;
    next=start->link;
    while(next->data!=ele && next!=NULL)
    {
        prev=next;
        next=next->link;
    }
    if(prev->data==ele)
    {
        prev->link=next->link;
        free(next);
        return;
    }
    printf("Element not exists\n");
}
