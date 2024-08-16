#include <stdio.h>

int c = 0;

// Function to solve the Knapsack problem using top-down dynamic programming
int knapsack_TD_DP(int n, int W, int B[][100], int w[], int v[]) {
    int c1, c2;
    c++;
    if (B[n][W] < 0) {
        if (W < w[n])
            B[n][W] = knapsack_TD_DP(n - 1, W, B, w, v);
        else {
            c1 = knapsack_TD_DP(n - 1, W, B, w, v);
            c2 = v[n] + knapsack_TD_DP(n - 1, W - w[n], B, w, v);
            B[n][W] = (c1 > c2) ? c1 : c2;
        }
    }
    return B[n][W];
}

// Function to print the items included in the optimal solution
void print_selected_items(int n, int W, int B[][100], int w[], int v[]) {
    printf("Items included in the optimal solution:\n");
    while (n > 0 && W > 0) {
        if (B[n][W] != B[n-1][W]) {  // Item n is included
            printf("Item %d (weight: %d, value: %d)\n", n, w[n], v[n]);
            W -= w[n];
        }
        n--;
    }
}

int main() {
    int n, W, i, j;
    
    // Taking the number of items as input
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int w[n+1], v[n+1];  // Arrays for weights and values (1-indexed)

    // Taking weights and values as input
    for (i = 1; i <= n; i++) {
        printf("Enter weight and value of item %d: ", i);
        scanf("%d %d", &w[i], &v[i]);
    }

    // Taking the knapsack capacity as input
    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    int B[n+1][100];  // DP table to store optimal solutions for subproblems

    // Initializing the DP table
    for (i = 0; i <= n; i++)
        for (j = 0; j <= W; j++)
            if (i == 0 || j == 0)
                B[i][j] = 0;
            else
                B[i][j] = -1;

    // Solving the Knapsack problem
    knapsack_TD_DP(n, W, B, w, v);

    // Printing the DP table
    printf("Knapsack table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++)
            printf("%d\t", B[i][j]);
        printf("\n");
    }

    // Printing the optimal value and the selected items
    printf("\nMaximum value: %d\n", B[n][W]);
    print_selected_items(n, W, B, w, v);

    return 0;
}
