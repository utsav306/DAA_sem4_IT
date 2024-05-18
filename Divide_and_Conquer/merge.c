#include<stdio.h>


void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void conquer(int arr[],int start,int mid,int end)
{
    int merged[end-start+1];
    int a=start;
    int x=0;
    int b=mid+1;

    while(a<=mid && b<=end )
    {
        if(arr[a]<arr[b])
        {
            merged[x]=arr[a];
            x++;
            a++;
        }
        else
        {
            merged[x]=arr[b];
            b++;
            x++;
        }
    }


    while(a<=mid)
    {
           merged[x]=arr[a];
            x++;
            a++;
    }
    while(b<=end)
    {
            merged[x]=arr[b];
            b++;
            x++;
    }
    for(int i=0;i<x;i++)
    {
        arr[i]=merged[i];
    }

}


void mergeSort(int arr[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        conquer(arr,start,mid,end);
    }

    else
    return;
}

int main()
{
    int arr[]={45,90,12,34,56};
    int n=5;
    print(arr,n);
    printf("\n");

    mergeSort(arr,0,n-1);
    print(arr,n);
}





