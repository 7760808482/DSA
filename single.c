#include<stdio.h>
#include<stdlib.h>
struct node
{
    int usn;
    char name[20];
    char prog[20];
    int sem;
    double phno;
    struct node *link;
};
struct node *new;
struct node *head=NULL;
int count=0;

struct node* create()
{
    new = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter the USN: ");
    scanf("%d", &new->usn);

    printf("Enter the name: ");
    scanf("%s", new->name);

    printf("Enter the program: ");
    scanf("%s", new->prog);

    printf("Enter the sem: ");
    scanf("%d", &new->sem);

    printf("Enter the phone no: ");
    scanf("%lf", &new->phno);

    new->link = NULL;
    return new;
}

void display()
{
    struct node *i;
    if(head==NULL)
    {
        printf("Linked list is empty");
        return;
    }
    i=head;
    while(i!=NULL)
    {
        printf("usn:%d\nname:%s\nprogram:%s\nsem:%d\nphone_no:%lf",i->usn,i->name,i->prog,i->sem,i->phno);
        i=i->link;
    }
    printf("Number of elements in the linked list are:%d",count);
}

void insfromfront()
{
    new=create();
    if(head==NULL)
        head=new;
    else
    {
        new->link=head;
        head=new;
    }
    count++;
}

void insfromend()
{
    struct node *i;
    new=create();
    if(head==NULL)
        head=new;
    else
    {
        i=head;
        while(i->link!=NULL)
        {
            i=i->link;
        }
        i->link=new;
    }
    count++;
}

void delfromfront()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    temp=head;
    head=head->link;
    printf("Deleted student details are:");
    printf("usn:%d\nname:%s\nprogram:%s\nsem:%d\nphone_no:%lf",temp->usn,temp->name,temp->prog,temp->sem,temp->phno);
    free(temp);
    count--;
}

void delfromend()
{
    struct node *i, *temp;

    if(head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    // Case 1: only one node
    if(head->link == NULL)
    {
        temp = head;
        head = NULL;
    }
    else
    {
        i = head;
        while(i->link->link != NULL)
            i = i->link;

        temp = i->link;
        i->link = NULL;
    }

    printf("Deleted student details:\n");
    printf("USN:%d\nName:%s\nProgram:%s\nSem:%d\nPhone:%lf\n",
           temp->usn, temp->name, temp->prog, temp->sem, temp->phno);

    free(temp);
    count--;
}

int main()
{
    int ch,i,n,ch1;
    while(1)
    {
        printf("\n\n----------MENU------------");
        printf("\n1.Inserting no of students from front\n2.display\n3.stack operation\n4.Reverse stack operation\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of students:");
                   scanf("%d",&n);
                   for(i=0;i<n;i++)
                   {
                       insfromfront();
                   }
                   break;
            case 2:display();
                   break;
            case 3:printf("Implementing stack using linked list");
                   printf("Enter your choice\n1.push\n2.pop\n");
                   scanf("%d",&ch1);
                   switch(ch1)
                   {
                       case 1:insfromfront();
                              break;
                       case 2:delfromfront();
                              break;
                       default:printf("INVALID INPUT");
                   }
                   break;
            case 4:printf("Implementing the reverse stack using linked list");
                   printf("Enter your choice\n1.push\n2.pop\n");
                   scanf("%d",&ch1);
                   switch(ch1)
                   {
                       case 1:insfromend();
                              break;
                       case 2:delfromend();
                              break;
                       default:printf("INVALID INPUT");
                   }
                   break;
            case 5:exit(0);
                   break;
            default:printf("INVALID INPUT");
        }
    }
}