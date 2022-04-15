#include<bits/stdc++.h>
using namespace std;
int dirs[2][2] = {{0, 1}, {1, 0}};
vector<vector<int>> memeory;
int dp(int x, int y, int n, int m, vector<vector<int>>& grid) {
    //base case
    if(x >= n || y >= m) return 0;
    if(x == n - 1 && y == m -1)  return memeory[x][y] = grid[x][y];
    if(memeory[x][y] != -1)  return memeory[x][y];

    if(x == n -1)  return memeory[x][y] = grid[x][y] + dp(x, y + 1, n, m, grid);
    else if(y == m -1)  return memeory[x][y] = grid[x][y] + dp(x + 1, y, n, m, grid);
    else {
         return memeory[x][y] = grid[x][y] + max(dp(x, y + 1, n, m, grid), dp(x + 1, y, n, m, grid));
    }
}
int maxValue(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    memeory = vector<vector<int>>(n, vector<int>(m, -1));
    return dp(0, 0, n, m, grid);
}
// 动态规划
int maxValue(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) continue;
            if(i == 0) {
                dp[i][j] = dp[i][j - 1];
            }
            else if(j == 0) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            dp[i][j] += grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    return 0;
}