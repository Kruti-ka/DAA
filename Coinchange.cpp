#include <iostream>
using namespace std;

int countWays(int coins[], int n, int sum) {
    int dp[sum + 1]; // Create a dp array to store the solutions to subproblems
    dp[0] = 1;       // There's 1 way to make the sum 0 (using no coins)

    // Initialize all other values in dp array as 0
    for (int i = 1; i <= sum; i++) {
        dp[i] = 0;
    }

    // Iterate through all coins
    for (int i = 0; i < n; i++) {
        // Update the dp array for sums from coins[i] to sum
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[sum]; // Return the total number of ways to make the sum
}

int main() {
    int coins1[] = {1, 2, 3};
    int sum1 = 4;
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    cout << "Number of ways to make sum " << sum1 << " is " << countWays(coins1, n1, sum1) << endl;

    int coins2[] = {2, 5, 3, 6};
    int sum2 = 10;
    int n2 = sizeof(coins2) / sizeof(coins2[0]);
    cout << "Number of ways to make sum " << sum2 << " is " << countWays(coins2, n2, sum2) << endl;

    return 0;
}