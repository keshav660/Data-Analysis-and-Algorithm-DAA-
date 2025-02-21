#include <bits/stdc++.h>
using namespace std;

// Function to solve 0/1 Knapsack
int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n = 4, W = 8; // Number of items and max weight capacity
    vector<int> wt = {2, 3, 4, 5}; // Weights of items
    vector<int> val = {3, 4, 5, 6}; // Values of items

    cout << "Maximum Profit: " << knapsack(W, wt, val, n) << endl;
    return 0;
}
