#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum) {
    // Create a 2D array to store results of subproblems
    bool dp[n+1][sum+1];

    // If sum is 0, then answer is true (empty subset)
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false;

    // Fill the dp table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i-1]) {
                dp[i][j] = dp[i-1][j];  // Exclude the current element
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - set[i-1]]; // Include or exclude
            }
        }
    }

    // Return the final result
    return dp[n][sum];
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, n, sum))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}