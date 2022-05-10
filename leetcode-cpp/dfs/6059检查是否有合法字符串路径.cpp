#include<bits/stdc++.h>
using namespace std;
// dfs + 剪枝
// 用visited记录状态 (x, y, z)表示状态
int m, n;
int dirs[2][2] = {{0, 1}, {1, 0}};
vector<vector<vector<bool>>> visited;
bool dfs(int x, int y, int c, vector<vector<char>>& grid) {
    bool res= false;
    // 右括号大于左括号
    if(c < 0) return false;
    // 左括号的数量远大于右括号
    if(c > m - x + n - y + 1) return false;
    // 重复访问
    if(visited[x][y][c]) return false;
    if(x == m - 1 && y == n - 1) return c == 1;
    visited[x][y][c] = true;
    c += grid[x][y] == '(' ? 1 : -1;
    return (x + 1 < m && dfs(x + 1, y, c, grid)) || (y + 1 < n && dfs(x, y + 1, c, grid));
}
bool hasValidPath(vector<vector<char>>& grid) {
    m = grid.size();
    n = grid[0].size();
    if((m + n - 1) % 2 == 1) return false;
    if(grid[m - 1][n - 1] == '(') return false;
    visited = vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>((m + n) / 2 + 1, false)));
    return dfs(0, 0, 0, grid);
}
// bfs剪枝
