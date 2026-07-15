#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int low, int high)
{
    int pivot=a[low];
    int i=low+1;
    int j=high;
    int temp;
    while(1)
    {
        while(i<=high && a[i]<=pivot)
        {
            i++;
        }
        while(a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            temp=a[low];
            a[low]=a[j];
            a[j]=temp;
            return j;
        }
    }
    
}
void quicksort(int a[],int low,int high)
{
    if (low < high)
    {
        int p=partition (a,low,high);
        quicksort (a,low,p-1);
        quicksort (a,p+1,high);
    }
}
int main()
{
    int *a;
    int n,i;
    clock_t start,end;
    double time_taken;
    printf("Enter the number of elements is greater then 5000:");
    scanf("%d",&n);
    a=(int *)malloc (n* sizeof(int));
    if (a==0)
    {
        printf("memory not allocated");
        return 0;

    }
    srand(time(0));
    for(i=0;i<n;i++)
    {
        a[i]=rand()%1000;
    }
    start=clock();
    quicksort(a,0,n-1);
    end=clock();
    time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("The time taken to sort %d elements is %f seconds\n",n,time_taken);
    

}
