#include<stdio.h>
#define max 100
#define inf 9999

int main()
{
    int i,j,k,n;
    int path[max][max];
    
    printf("Enter the number of vertex:");
    scanf("%d",&n);
    printf("Enter the adjancey matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&path[i][j]);
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if (path[i][k]!=inf && path[k][j]!=inf &&
                    path[i][k]+path[k][j] < path[i][j])
                {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
    printf("shortest path:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (path[i][j]==inf)
            {
                printf("inf");
            }
            else
            {
                printf("%d ",path[i][j]);
            }
        }
        printf("\n");

    }
    return 0;
}