#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j,n,min,temp;
void selection_sort(int arr[],int n)
{
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;

            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
int main()
{
    int *arr;
    clock_t start,end;
    double time_taken;
    printf("Enter the number of elements is greater than 5000:");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    
    if (arr==0)
    {
        printf("Memory not allocated");

    }
    srand(time(0));
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%1000;
        start=clock();
        selection_sort(arr,n);
        end=clock();
        time_taken=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Time taken for sorting %d elements is %f seconds\n",n,time_taken);
        free(arr);
        return 0;
    }
}
