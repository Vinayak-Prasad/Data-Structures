#include<stdio.h>
#include<stdlib.h>
#define size 3
int queue[size],front=-1,rear=-1;
void insert_lq();
void delete_lq();
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
            insert_lq();
            break;
        case 2:
            delete_lq();
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

void insert_lq()
{
    int item;
    if(rear==size-1)
    {
        printf("Queue is full\n");
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
        rear=rear+1;
    }
    queue[rear]=item;
    return;
}

void delete_lq()
{
    int d;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
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
        front=front+1;
    }
    printf("Deleted element:%d\n",d);
    return;
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    for(int i=front;i<=rear;i++)
        printf("%d\n",queue[i]);
    return;
}


