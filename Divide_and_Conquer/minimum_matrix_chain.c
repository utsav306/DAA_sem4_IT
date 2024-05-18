#include<stdio.h>
#define min 9999999
int mcm(int i,int j,int arr[])
{
    int k;
    if(i==j)
    return 0;
    int m=min;
    for(k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+mcm(i,k,arr)+mcm(k+1,j,arr);
        if(steps<m)
        m=steps;
    }

    return m;
}
int main()
{
    int arr[4]={4,5,3,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    int ans= mcm(1,n-1,arr);
    printf("Minimum steps required are : %d ",ans);
}