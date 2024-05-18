#include <stdio.h>

// https://www.youtube.com/watch?v=GVFXYrMRqFw

// You can visit above link for better understanding
void findMinMax(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {  // If there's only one element
        if (*min > arr[low]) {
            *min = arr[low];
        }
        if (*max < arr[low]) {
            *max = arr[low];
        }
        return;
    }

    if (high == low + 1) {  // If there are two elements
        if (arr[low] < arr[high]) {
            if (*min > arr[low]) {
                *min = arr[low];
            }
            if (*max < arr[high]) {
                *max = arr[high];
            }
        } else {
            if (*min > arr[high]) {
                *min = arr[high];
            }
            if (*max < arr[low]) {
                *max = arr[low];
            }
        }
        return;
    }

    int mid = (low + high) / 2;
    findMinMax(arr, low, mid, min, max);
    findMinMax(arr, mid + 1, high, min, max);
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    int max = arr[0];

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum element is %d\n", min);
    printf("Maximum element is %d\n", max);

    return 0;
}
