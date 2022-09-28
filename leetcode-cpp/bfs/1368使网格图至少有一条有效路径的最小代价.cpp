#include<bits/stdc++.h>
using namespace std;
int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int minCost(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    deque<pair<int, int>> dq;
    // 初始化
    dq.emplace_front(0, 0);
    dists[0][0] = 0;
    while(!dq.empty()) {
        auto [x, y] = dq.front(); dq.pop_front();
        if(visited[x][y]) continue;
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if(nx < 0 || nx >= m || ny < 0|| ny >= n || visited[nx][ny]) continue;
            int dis = 0;
            if(grid[x][y] == i + 1) {
                dis = dists[x][y];
                dq.emplace_front(nx, ny);
            } else {
                dis = dists[x][y] + 1;
                dq.emplace_back(nx, ny);
            }
            if(dists[nx][ny] > dis) dists[nx][ny] = dis;
        }
    }
    return dists[m - 1][n - 1];
}
int main() {
    return 0;
}