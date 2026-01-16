#include<stdio.h>
void hanoi(int n,char temp,char s,char d)
{
    if(n==1)
    {
        printf("move disk %d from %c to %c",n,s,d);
        return;
    }
    printf("move disk %c to %c",s,d);
    hanoi(n-1,s,d,temp);
    printf("Move disk %d from %c to %c",n,s,d);
    hanoi(n-1,temp,s,d);
}
int main()
{
    int n;
    printf("Enter the value:");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
}