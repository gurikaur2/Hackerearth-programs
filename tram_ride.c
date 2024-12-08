#include <stdio.h>
#include <limits.h>

// Function to find the minimum cost of traveling between two tram stations
int minimumCost(int N, int start, int finish, int ticket_cost[]) {
    int clockwise_cost = 0, anticlockwise_cost = 0;

    // Calculate the clockwise cost
    for (int i = start; i != finish; i = (i + 1) % N) {
        clockwise_cost += ticket_cost[i];
    }

    // Calculate the anticlockwise cost
    for (int i = start; i != finish; i = (i - 1 + N) % N) {
        anticlockwise_cost += ticket_cost[(i - 1 + N) % N];
    }

    // Return the minimum of the two costs
    return (clockwise_cost < anticlockwise_cost) ? clockwise_cost : anticlockwise_cost;
}

int main() {
    int N, start, finish;

    // Input number of stations
    printf("Enter the number of tram stations (N): ");
    scanf("%d", &N);

    int ticket_cost[N];

    // Input ticket costs between adjacent stations
    printf("Enter the ticket costs between adjacent stations: \n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &ticket_cost[i]);
    }

    // Input start and finish stations
    printf("Enter the start station (1 to %d): ", N);
    scanf("%d", &start);
    start--; // Convert to 0-based index

    printf("Enter the finish station (1 to %d): ", N);
    scanf("%d", &finish);
    finish--; // Convert to 0-based index

    // Calculate the minimum cost
    int result = minimumCost(N, start, finish, ticket_cost);

    // Output the result
    printf("The minimum cost to travel from station %d to station %d is: %d\n", start + 1, finish + 1, result);

    return 0;
}