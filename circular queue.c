#include<stdio.h>
#include<stdlib.h>
#define size 3
int queue[size],front=-1,rear=-1;
void insert_cq();
void delete_cq();
void display();
void main()
{
    int ch;
    while(1)
    {
        printf("1.Insert 2.Delete 3.Display 4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert_cq();
            break;
        case 2:
            delete_cq();
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

void insert_cq()
{
    int item;
    if((front==0 && rear==size-1) || (front==rear+1))
    {
        printf("Circular Queue is full\n");
        return;
    }
    printf("Enter the item to be inserted:\n");
    scanf("%d",&item);
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=(rear+1)%size;
    }
    queue[rear]=item;
    return;
}

void delete_cq()
{
    int d;
    if(front==-1 && rear==-1)
    {
        printf("Circular Queue is empty\n");
        return;
    }
    d=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
    printf("Deleted element: %d\n",d);
    return;
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Circular Queue is empty");
        return;
    }
    if(front<rear)
    {
        for(int i=front;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
    else
    {
        for(int i=front;i<=size-1;i++)
            printf("%d\n",queue[i]);
        for(int i=0;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
    return;
}
