#include<stdio.h>
#include<stdlib.h>
void convert();
void push(char);
char pop();
int pri(char);
char infix[50],postfix[50],s[30];
int top=-1;
int main()
{
    printf("Enter the infix expression:");
    scanf("%s",infix);
    convert();
    printf("The Postfix expression are:%s",postfix);
}
void push(char op)
{   
    top++;
    s[top]=op;
    
}
char pop()
{
    char temp;
    temp=s[top];
    top--;
    return temp;
}
int pri(char op)
{
    int p;
    switch(op)
    {
        case '$':p=-1;
        break;
        case '(':
        case ')':p=0;
        break;
        case '+':
        case '-':p=1;
        break;
        case '*':
        case '/':p=2;
        break;
        case '%':p=3;
        break;
        case '^':p=4;
        break;
    }
    return p;
}
void convert()
{
    int i=0,j=0;
    char temp,symb;
    push('$');
    for(i=0;infix[i]!='\0';i++)
    {
        symb=infix[i];
        switch(symb)
        {
            case '(':push(symb);
                break;
            case ')':temp=pop();
                while(temp!='(')
                {
                    postfix[j]=temp;
                    j++;
                    temp=pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(pri(s[top])>=pri(symb))
                {
                    temp=pop();
                    postfix[j]=temp;
                    j++;
                }
                push(symb);
                break;
            default:postfix[j]=symb;
                j++;
    }
}
    while(top>0)
    {
        temp=pop();
        postfix[j]=temp;
        j++;        
    }
    postfix[j]='\0';
}