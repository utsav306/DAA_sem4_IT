#include<stdio.h>
int max(int a,int b)
{
    if(a<b)
    return b;
    return a;
}
int jobSequence(int profit[],int deadline[],int n)
{
    int i;int k;int cost=0;
    int jobs=0;
    int maxDeadline=deadline[0];

    for(i=0;i<n;i++)
    {
        maxDeadline=max(deadline[i],maxDeadline);
    }

       int slots[100];
    for (i = 0; i < 100; i++) {
        slots[i] = -1;
    }

    for(i=0;i<n;i++)
    {
        for(k=deadline[i];k>0;k--)
        {
            if(slots[k]==-1)
            {
                slots[k]=i;
                cost=cost+profit[i];
                jobs++;
                break;
            }
        }

    }

    printf("Maximum Profit : %d \n",cost);
    printf("No of Jobs done : %d \n",jobs);
    printf("The sequence of jobs are : \n");
    for(i=1;i<=maxDeadline;i++)
    {
        if (slots[i] != -1) {
            printf("%d ", slots[i]);
        }
    }

    return 0;
}
int main()
{
    int profit[5]={90,54,12,3,4};
    int deadline[5]={6,6,2,1,3};
    int n=5;

    jobSequence(profit,deadline,n);

}