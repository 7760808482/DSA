#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char *name;
    int date;
    char *activity;
};
struct node *p;
void create()
{
    p=(struct node*)malloc(sizeof(struct node)*7);
    if(p==NULL)
    {
        printf("Memory is not allocated");
        return;
    }
}
void read()
{
    int i;
    char temp[50];
    for(i=0;i<7;i++)
    {
        printf("\nEnter the details of the day:%d\n",i+1);
        printf("\nEnter the name of the day:\n");
        scanf("%s",temp);
        p[i].name=(char*)malloc(strlen(temp)+1);
        strcpy(p[i].name,temp);
        printf("\nEnter the date:\n");
        scanf("%d",&p[i].date);
        printf("\nEnter the activity of the day:\n");
        scanf("%s",temp);
        p[i].activity=(char*)malloc(strlen(temp)+1);
        strcpy(p[i].activity,temp);
    }
}
void display()
{
    int i;
    for(i=0;i<7;i++)
        {
            printf("\n%s\t%d\t%s",p[i].name,p[i].date,p[i].activity);
        }
}

int main()
{  
    create();
    read();
    display();
}