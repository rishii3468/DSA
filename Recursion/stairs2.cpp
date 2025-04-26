#include <iostream>
#include <vector>

using namespace std;

int countWays(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    // Create a vector to store the number of ways to reach each step
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    // Fill the dp array using the recurrence relation
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        cout << countWays(n) << endl;
    }

    return 0;
}