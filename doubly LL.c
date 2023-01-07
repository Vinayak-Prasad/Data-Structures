#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display_ll(struct node *);
struct node *insert_before(struct node *);
struct node *delete_node(struct node *);

int main()
{
    int choice;
    do
    {
        printf("\n1.Create Linked List\n2.Display\n3.Insert Before\n4.Delete Specific node\n5.Exit");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:start=create_ll(start);break;
            case 2:start=display_ll(start);break;
            case 3:start=insert_before(start);break;
            case 4:start=delete_node(start);break;
        }
    }while(choice!=5);
    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("\nEnter -1 to end");
    scanf("%d",&num);
    while(num!=-1)
    {
        if(start==NULL)
        {
          new_node=(struct node*)malloc(sizeof(struct node));
          new_node->data=num;
          start=new_node;
          new_node->prev=NULL;
          new_node->next=NULL;
        }
        else
        {
            new_node=(struct node *)malloc(sizeof(struct node));
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->data=num;
            new_node->next=NULL;
        }
        printf("\nEnter data");
        scanf("%d",&num);
    }
    return start;
}

struct node *display_ll(struct node *start)
{
    struct node *ptr;
    if(start==NULL)
      printf("\nLINKED LIST IS EMPTY");
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node,*ptr;
    int num,val;
    if(start==NULL)
      printf("\nLINKED LIST IS EMPTY");
    else
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter data into inserted node");
        scanf("%d",&val);
        new_node->data=val;
        ptr=start;
        printf("\nEnter the data value of the node before which you want to insert a node");
        scanf("%d",&num);
        while(ptr->data!=num)
           ptr=ptr->next;
        ptr->prev->next=new_node;
        new_node->prev=ptr->prev;
        new_node->next=ptr;
        ptr->prev=new_node;
    }
    return start;
}

struct node *delete_node(struct node *start)
{
    int val;
    struct node *ptr;
    if(start==NULL)
      printf("\nUNDERFLOW");
    else
    {
        ptr=start;
        printf("\nEnter the data value of the node to be deleted");
        scanf("%d",&val);
        while(ptr->data!=val)
          ptr=ptr->next;
        if(ptr==start)
        {
            ptr->next->prev=NULL;
            start=ptr->next;
            free(ptr);
        }
        else if(ptr->next==NULL)
        {
            ptr->prev->next=NULL;
            free(ptr);
        }
        else
        {
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(ptr);
        }
    }
    return start;
}
