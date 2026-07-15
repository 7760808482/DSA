#include<stdio.h>
#define max 1000
#define inf 9999

int main()
{
    int i,j,a,n,b,min;
    int visited[max]={0};
    int cost[max][max];
    int total_cost=0,edges=0;
    
    printf("Enter the number of vertex:");
    scanf("%d",&n);
    printf("Enter the adjancey matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if (cost[i][j]==0)
                cost[i][j]=inf;
                
        }
    }
    visited[0]=1;
    printf("Edges in MST:");
    while(edges < n-1)
    {
        min = inf;
        
    
            for (i=0; i<n;i++)
            {
                if (visited[i])
                {
                    for(j=0;j<n;j++)
                    {
                        if (!visited[j] && cost[i][j] < min)
                        {
                            min = cost[i][j];
                                a=i;
                                b=j;
                    
                        }   
                    }

                }
            }
    
        if (min == inf)
        {
            printf("Graph is not connected");
            
        }
        printf("%d-->%d=%d",a,b,min);
        total_cost+=min;
        visited[b]=1;
        edges++;
    }
    printf("Minimum Cost=%d",total_cost);
    
}