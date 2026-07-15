#include<stdio.h>
#define max 100

int main()
{
    int i,j,n,found,count=0;
    int visited[max]={0};
    int graph[max][max];
    int indeegre[max]={0};
    
    printf("Enter the number of vertex:");
    scanf("%d",&n);
    
    printf("Enter the adjancey matrix:\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
            
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(graph[i][j]==1)
            {
                indeegre[j]++;
            }
        }
    }
    printf("\n Topologiacl oreder:\n");
    while (count<n)
    {
        found=0;
        for (i=0;i<n;i++)
        {
            if (indeegre[i]==0 && !visited[i])
            {
                printf("%d ",i);
                visited[i]=1;
                count++;
                found=1;
                
                for (j=0;j<n;j++)
                
                {
                    if (graph[i][j]==1)
                    {
                        indeegre[j]--;
                    }
                }
                
            }
        }
        if (!found)
        {
            printf("Graph is not conncted");
            return 1;
        }
    }
    
    
}
