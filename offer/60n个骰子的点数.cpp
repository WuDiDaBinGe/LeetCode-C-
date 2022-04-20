#include<bits/stdc++.h>
using namespace std;
// dp
vector<double> dicesProbability(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1));
    // base case
    for(int j = 1; j <= 6; j++){
        dp[1][j] = 1;
    }
    for(int i = 0; i <= n; i++) {
        dp[i][i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = i + 1; j <= 6 * n + 1; j++) {
            dp[i][]
        }
    }
}
int main() {
    return 0;
}