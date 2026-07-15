#include<stdio.h>

int i,j,n,k,target;
int set[20],subset[20];

void subsetsum(int i,int k , int sum)
{
    if (sum==target)
    {
        printf("Subset:");
        for (j=0; j<k; j++)
            printf("{ %d }", subset[j]);
        printf("\n");
        return;
    }
    if(i==n || sum>target)
        return;
    else
    {
        subset[k] = set[i];
        subsetsum(i+1,k+1,sum+set[i]);
        subsetsum(i+1,k,sum);
    }
}
int main()
{
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&set[i]);
    printf("Enter the target sum number:");
    scanf("%d",&target);
    subsetsum(0,0,0);
    return 0;
}