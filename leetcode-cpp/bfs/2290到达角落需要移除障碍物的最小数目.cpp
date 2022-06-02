#include<bits/stdc++.h>
using namespace std;
int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
// 使用优先队列 dijstra思想
struct HeapNode {
    int c, x, y;
    bool operator < (const HeapNode& hp) const {
        return c > hp.c;
    }
};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<HeapNode> pq;
        int res = INT_MAX;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        pq.push((HeapNode){0, 0, 0});
        while(!pq.empty()) {
            HeapNode hp = pq.top(); pq.pop();
            // 去掉时间复杂度会变高
            if(visited[hp.x][hp.y]) continue;
            visited[hp.x][hp.y] = true;
            if(hp.x == m - 1 && hp.y == n - 1) {
                res = min(res, hp.c);
            }
            for(int i = 0; i < 4; ++i) {
                int nx = hp.x + dirs[i][0], ny = hp.y + dirs[i][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                if(grid[nx][ny] == 1) pq.push((HeapNode){hp.c + 1, nx, ny});
                else pq.push((HeapNode){hp.c, nx, ny});
            }
        }
        return res;
    }
};
// 数组记录 双端队列 0-1bfs思想
int minimumObstacles(vector<vector<int>>& grid) {
    deque<pair<int, int>> dq;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    dist[0][0] = 0;
    dq.emplace_front(0, 0);
    while(!dq.empty()) {
        auto [x, y] = dq.front(); dq.pop_front();
        // 扩展过 
        if(visited[x][y]) continue;
        // 加入扩展集合
        visited[x][y] = true;
        // 更新最小距离信息
        for(int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
            int g = grid[nx][ny];
            int dis = g + dist[x][y];
            if(dist[nx][ny] > dis) dist[nx][ny] = dis;
            g == 0 ? dq.emplace_front(nx, ny) : dq.emplace_back(nx, ny);
        }
    }
    return dist[m-1][n-1];
}
int main() {
    return 0;
}