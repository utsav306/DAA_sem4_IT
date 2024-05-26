#include <stdio.h>

float knapSack(int n, float weight[], float profit[], int capacity) {
    float x[500], tp = 0;
    int i;

    // Initialize x array to 0
    for(i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    int u = capacity;

    // Process each item
    for(i = 0; i < n; i++) {
        if(u < weight[i]) {
            break;
        }
        x[i] = 1.0;
        tp = tp + profit[i];
        u = u - weight[i];
    }

    // If there's still capacity, take fraction of the next item
    if(i < n) {
        x[i] = u / weight[i];
        tp = tp + x[i] * profit[i];
    }

    // Output the fraction of weights taken
    printf("\nThe fractions of weights taken are:\n");
    for(i = 0; i < n; i++) {
        printf("Item %d: %f\n", i + 1, x[i]);
    }
    
    return tp;
}

int main() {
    int i, j, n;
    float weight[20], profit[20], ratio[20];
    
    // Input number of objects
    printf("Enter number of objects: ");
    scanf("%d", &n);
    
    // Input weights and profits of each object
    printf("Enter weight and profit of each object:\n");
    for(i = 0; i < n; i++) {
        printf("Object %d\n", i + 1);
        printf("Weight: ");
        scanf("%f", &weight[i]);
        printf("Profit: ");
        scanf("%f", &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }
    
    // Input capacity of knapsack
    printf("Enter capacity of knapsack: ");
    int cap;
    scanf("%d", &cap);
    
    // Sort objects based on profit/weight ratio in descending order
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(ratio[j] < ratio[j + 1]) {
                // Swap ratios
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;
                
                // Swap weights
                float temp1 = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp1;
                
                // Swap profits
                float temp2 = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp2;
            }
        }
    }
    
    // Calculate total profit
    float tp = knapSack(n, weight, profit, cap);
    printf("\nTotal profit is: %f\n", tp);

    return 0;
}
