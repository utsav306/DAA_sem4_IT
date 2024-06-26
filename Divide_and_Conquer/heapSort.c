#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void heap(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[i], &arr[largest]);
        heap(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        heap(arr, n, i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[i], &arr[0]);

        heap(arr, i, 0);
    }
}

int main(){

    int size;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter the elements of the array: ");
    for(int i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal  array: ");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }

    //Calling the function to sort array: 
    heapSort(arr, size);
    printf("\nSorted array: ");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}