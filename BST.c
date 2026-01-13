#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
struct node*root=NULL;
struct node*create(int val)
{
    struct node*new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
}
void insert(int value)
{
    struct node*create(int value);
    struct node*new,*parent,*current;
    new=create(value);
    current=root;
    parent=NULL;
    while(current!=NULL)
    {
        current=parent;
    }
    if(current->data>value)
    
        current=current->left;
    
    else
    {
        current=current->right;
    }
    if(parent->data>value)
    {
        parent=parent->left;
    }
    else{
        parent=parent->right;
    }
}
void inorder(struct node*temp)
{
    while(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d",temp->data);
        inorder(temp->right);
    }
}
void preorder(struct node*temp)
{
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(struct node*temp)
{
    while(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d",temp->data);
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("1.Create a BST\n2.inorder\n3.preorder\n4.postorder\n5.exit");
        printf("\nEnter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                int val;
                printf("Enter the value:");
                scanf("%d",&val);
                insert(val);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice ");    
        }
    }
   
}
   