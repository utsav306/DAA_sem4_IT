#include<stdio.h>


void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}


int partition(int arr[],int low,int high)
{
    int piv=arr[low];

    int i=low+1;
    int j=high;

do
{
    while(arr[i]<=piv)
    {
        i++;
    }
    while(arr[j]>piv)
    {
        j--;
    }

    if(i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

} while (i<j);

    
        int temp=arr[low];
        arr[low]=arr[j];
        arr[j]=temp;

        return j;

}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


int main()
{
    int arr[]={45,90,12,34,56};
    int n=5;
    print(arr,n);
    printf("\n");

    quickSort(arr,0,n-1);
     print(arr,n);
}