#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int temp[],int low, int mid, int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    while(i <= mid && j<=high)
    {
        if ( a[i] <= a[j] )
        {
            temp[k++]=a[i++];
    
        }
        else
        {
            temp[k++]=a[j++];

        }
        while (i<=mid)
        {
            temp[k++]=a[i++];

        }
        while (j <= high)
        {
            temp[k++]=a[j++];
        }
        for(i=low;i<=high;i++)
        {
            a[i] = temp[k];
        }


    }
}
void mergeSort(int a[],int temp[],int low , int high)
{
    if (low<high)
    {
        int mid = (low+high)/2;
        mergeSort(a,temp,low,mid);
        mergeSort(a,temp,mid+1,high);
        merge(a,temp,low,mid,high);
    }
}
int main()
{
    int *a;
    time_t start, end;
    double time_taken;
    int i,n;
    printf(("Enter the number of elemets is greater then 5000:"));
    scanf("%d",&n);
    a = (int *) malloc (n * sizeof (int));
    if (a==NULL)
    {
        printf("Memory not allocated");

    }
    srand(time(0));
    for (i=0;i<n;i++)
    {
        a[i] = rand()%10000;
    }
    start = clock();
    int *temp = (int *) malloc (n * sizeof (int));
    mergeSort(a,temp,0,n-1);
    end = clock();
    time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken to sort %d elemnts in %f seconds",n,time_taken);
    free(temp);
    return 0;
}
