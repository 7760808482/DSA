#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[10],dept[50],des[50];
    int phno,ssn;
    float sal;
    struct node*next;
    struct node*prev;
};
struct node*head=NULL;
struct node*create()
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Entert the SSN");
    scanf("%d",&new->ssn);
    printf("Enter the name");
    scanf("%s",new->name);
    printf("Enter the department");
    scanf("%s",new->dept);
    printf("Enter the designation");
    scanf("%s",new->des);
    printf("Enter the phone number");
    scanf("%d",&new->phno);
    printf("Enter the salary");
    scanf("%f",&new->sal);
    new->next=NULL;
    new->prev=NULL;
    return new;
}
void insatend()
{
    struct node*new,*i;
    new=create();
    if(head==NULL)
    {
        head=new;   
        return;
    }
    i=head;
    while(i->next!=NULL)
    {
    i->next=new;
    new->prev=i;
}
}
void insatfront()
{
    struct node*new;
    new=create();
    if(head==NULL)
    {
        head=new;   
        return;
    }
    new->next=head;
    head->prev=new;
    head=new;
}
void deletefront()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void deleteend()
{
    struct node*temp,*i;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    i=head;
    while(i->next!=NULL)
    {
        temp=i;
        i=i->next;
    }
    temp->next=NULL;
    free(i);
}
void display()
{
    struct node*temp;
    temp=head;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    while(temp!=NULL)
    {
        printf("SSN:%d\n",temp->ssn);
        printf("Name:%s\n",temp->name);
        printf("Department:%s\n",temp->dept);
        printf("Designation:%s\n",temp->des);
        printf("Phone number:%d\n",temp->phno);
        printf("Salary:%.2f\n",temp->sal);          
        temp=temp->next;
    }
}
int main()
{   
    int ch,i,n;
    while(1)
    {
        printf("1.create a DLL\n2.Insert at end\n3.Insert at front\n4.Delete at front\n5.Delete at end\n6.Display\n7.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);   
        switch(ch)
        {
            case 1:
            printf("Enter the number of employee");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            insatend();
            break;
            case 2:insatend();
            break;
            case 3:insatfront();
            break;
            case 4:deletefront();
            break;
            case 5:deleteend();
            break;
            case 6:display();
            break;
            case 7:exit(0);
            break;
            default:printf("Invalid choice");
        }
    }       
}         
                        