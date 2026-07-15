#include<stdio.h>

int max(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}
int main()
{
    int dp[20][20],wt[20],val[20];
    int i,j,n,w;

    printf("Enter the number of item:");
    scanf("%d",&n);
    printf("Enter the weight:");
    for(i=1;i<=n;i++)
        scanf("%d",&wt[i]);
    printf("Enter the value:");
    for(j=1;j<=n;j++)
        scanf("%d",&val[j]);
    printf("Enter the capacity:");
    scanf("%d",&w);

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if (i==0 || j==0)
                dp[i][j]=0;
            else if (wt[i]<=j)
                dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]);
            else
                dp[i][j]=dp[i-1][j];

        }
    }
    printf("Max capacity:%d",dp[n][w]);
    return 0;
}