#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void push(int);
int pop();
void palindrome();
void display();

int s[MAX];
int top=-1;

void main()
{
    int ch,item;
    while(1)
    {
        printf("\n\n\n---------menu---------");
        printf("\n1.Push\n2.Pop\n3.Palindrome\n4.Display\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element to be pushed:");
                   scanf("%d",&item);
                   push(item);
                   break;
            case 2:item=pop();
                   if(item==-1)
                    printf("stack underflow");
                   else
                    printf("element poped:%d",item);
                    break;
            case 3:palindrome();
                   break;
            case 4:display();
                   break;
            case 5:exit(0);
                   break;
            default:printf("INVALID INPUT");
        }
    }
}

void push(int n)
{
    if(top==MAX-1)
    {
        printf("stack overflow");
        return;
    }
    top++;
    s[top]=n;
}

int pop()
{
    int ele;
    if(top==-1)
    {
        return -1;
    }
    ele=s[top];
    top--;
    return ele;
}

void palindrome()
{
    int i, flag = 1;
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    for (i = 0; i <= top / 2; i++)
    {
        if (s[i] != s[top - i])
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("It is a palindrome");
    else
        printf("It is not a palindrome");
}


void display()
{
    int i;
    if(top==-1)
    {
        printf("stack underflow");
        return;
    }
    printf("stack elements:");
    for(i=top;i>=0;i--)
    {
        printf("\n%d",s[i]);
    }
}