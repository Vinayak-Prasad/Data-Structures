#include<stdio.h>
#include<stdlib.h>
#define size 3
int stack[size],top=-1,item;
void push();
int pop();
void display();
void main()
{
    int choice,del;
    while(1)
    {
        printf("1.Push 2.Pop 3.Display 4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            del=pop();
            if(del==0)
                printf("No element\n");
            else
                printf("Deleted Element: %d\n",del);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }

    }
}

void push()
{
    if(top==size-1)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        printf("Enter an element:");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
    }
}

int pop()
{
    int d;
    if(top==-1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    else
    {
        d=stack[top];
        top=top-1;
        return(d);
    }
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }

}
