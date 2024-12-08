#include <stdio.h>

// Function to count the number of good citizens
int countGoodCitizens(int N, int Behaviour[]) {
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        int leftNeighbor = (i == 0) ? 0 : Behaviour[i - 1];
        int rightNeighbor = (i == N - 1) ? 0 : Behaviour[i + 1];
        int average = (leftNeighbor + rightNeighbor) / 2;
        
        if (Behaviour[i] > average) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int N;
    
    // Read the number of citizens
    printf("Enter the number of citizens: ");
    scanf("%d", &N);
    
    int Behaviour[N];
    
    // Read the behavior scores of citizens
    printf("Enter the behavior scores: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &Behaviour[i]);
    }
    
    // Calculate the number of good citizens
    int goodCitizens = countGoodCitizens(N, Behaviour);
    
    // Print the result
    printf("Number of good citizens: %d\n", goodCitizens);
    
    return 0;
}
