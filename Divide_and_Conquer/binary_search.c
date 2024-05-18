#include<stdio.h>
int BS(int arr[],int key,int low,int high)
{
    if(low>high)
    return -1;

    int mid=(low+high)/2;

    if(arr[mid]==key)
    return mid;

    if(arr[mid]>key)
    {
       return BS(arr,key,low,mid-1);
    }
     if(arr[mid]<key)
    {
       return BS(arr,key,mid+1,high);
    }
}
int main()
{
    int arr[5]={23,45,67,89,90}; // array
    int key=23; //search element
    int low=0;
    int high=4; // array size-1
    
   int  ans=BS(arr,key,low,high);
    if(ans==-1)
    printf("Element Not Found");
    else
    printf("Element found at index : %d ",ans);
}