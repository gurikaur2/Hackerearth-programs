#include <stdio.h>
#include <stdlib.h>

// Function to calculate absolute value
int abs(int x) {
    return (x < 0) ? -x : x;
}

// Function to calculate the maximum number of separations
int maxSeparations(int N, int arr[], int K) {
    int separations = 0;
    int currentCost = 0;

    for (int i = 1; i < N; i++) {
        int cost = abs(arr[i] - arr[i - 1]);
        
        if (currentCost + cost <= K) {
            separations++;
            currentCost += cost;
        } else {
            break;
        }
    }

    return separations;
}

int main() {
    int N, K;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int arr[N];
    
    // Read the array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the maximum allowed cost
    printf("Enter the maximum allowed cost: ");
    scanf("%d", &K);

    // Calculate and print the maximum number of separations
    int result = maxSeparations(N, arr, K);
    printf("Maximum number of separations: %d\n", result);

    return 0;
}
