#include <stdio.h>

// Function to calculate the maximum number of candles that can be burned
int maximumCandles(int N, int K) {
    int totalCandles = N; // Start with the initial number of unburnt candles
    int burntCandles = 0; // Store burnt candles for recycling

    while (N >= K) {
        int newCandles = N / K; // Number of new candles created
        burntCandles = N % K;  // Remaining burnt candles after making new candles
        totalCandles += newCandles;
        N = newCandles + burntCandles; // Update the number of candles for next iteration
    }

    return totalCandles;
}

int main() {
    int N, K;

    // Input the number of initial candles and the number of burnt candles required for a new one
    printf("Enter the number of initial unburnt candles (N): ");
    scanf("%d", &N);

    printf("Enter the number of burnt candles required to make a new one (K): ");
    scanf("%d", &K);

    // Calculate the maximum number of candles that can be burned
    int result = maximumCandles(N, K);

    // Output the result
    printf("The maximum number of candles that can be burned: %d\n", result);

    return 0;
}