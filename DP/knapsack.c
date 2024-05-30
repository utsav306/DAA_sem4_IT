#include<stdio.h>
#define n 4
#define min -999999

int maxx(int a,int b)
{
    return (a>b)?a:b;
}
int f(int ind,int weight[],int profit[],int maxW)
{
    if(ind>=n)
    return 0;

    int take= min;
    int not_take=0+f(ind+1,weight,profit,maxW);

    if(weight[ind]<=maxW)
    take=profit[ind]+f(ind+1,weight,profit,maxW-weight[ind]);

    return maxx(take,not_take);
}

int main()
{
    int weight[n]={45,12,78,90};
    int profit[n]={100,23,156,17};
    int maxW=150;

    int ans=f(0,weight,profit,maxW);
    printf("Maximum profit is : %d ",ans);
}