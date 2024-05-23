#include<stdio.h>
float knapSack(int n,float weight[],float profit[],int capacity){
    float x[n],tp=0;
    int i;
    for( i=0;i<n;i++){
        x[i]=0.0;
    }
  int u=capacity;
  for( i=0;i<n;i++){
    if(u<weight[i]){
        break;
    }
    x[i]=1.0;
    tp=tp+profit[i];
    u=u-weight[i];
  }  
  if(i<n){
    x[i]=u/weight[i];
    tp=tp+x[i]*profit[i];
  }
  printf("\nthe amount of weights is:\n");
  for(i=0;i<n;i++){
    printf("%f ",x[i]);
  }
  return tp;
}
int main(){
    int i,j,n;
    float weight[20],profit[20],ratio[20];
    printf("enter no of objects: ");
    scanf("%d",&n);
    printf("weight profit\n");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&weight[i],&profit[i]);
        ratio[i]=profit[i]/weight[i];
    }
    printf("capacity: ");
    int cap;
    scanf("%d",&cap);
   
    for(i=0;i<n-1;i++){
       for(j=0;j<n-1-i;j++){
        if(ratio[j]<ratio[j+1]){
            float temp=ratio[j];
            ratio[j]=ratio[j+1];
            ratio[j+1]=temp;

            float temp1=weight[j];
            weight[j]=weight[j+1];
            weight[j+1]=temp1;

            float temp2=profit[j];
            profit[j]=profit[j+1];
            profit[j+1]=temp2;
        }
       } 
    }
      float tp=knapSack(n,weight,profit,cap);
      printf("\ntotal profit is %f\n",tp);

       }
