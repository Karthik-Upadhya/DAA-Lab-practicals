#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n, amount;

    // Input number of coins
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);

    // Input coin denominations
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Input amount
    cout << "Enter amount: ";
    cin >> amount;

    // DP array
    vector<int> dp(amount + 1, INT_MAX);

    // Base case
    dp[0] = 0;

    // Calculate minimum coins
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {

            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i],
                            dp[i - coins[j]] + 1);
            }
        }
    }

    // Display result
    if (dp[amount] == INT_MAX) {
        cout << "Change cannot be made." << endl;
    }
    else {
        cout << "Minimum number of coins required = "
             << dp[amount] << endl;
    }
    cout<<"Karthik Upadhya\n";
    cout<<"92460118138\n";
    cout<<"5-EN18\n";

    return 0;
}
