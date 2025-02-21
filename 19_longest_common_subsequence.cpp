#include <bits/stdc++.h>
using namespace std;

// Function to find the Longest Common Subsequence (LCS)
int lcs(string X, string Y) {
    int m = X.length(), n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string X, Y;
    
    // Taking runtime input
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;
    
    // Calling LCS function
    cout << "Length of Longest Common Subsequence: " << lcs(X, Y) << endl;
    
    return 0;
}
