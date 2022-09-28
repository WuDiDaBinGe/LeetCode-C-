#include<bits/stdc++.h>
using namespace std;

char dirs_c[4] = {'^', 'v', '<', '>'};
int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
    deque<pair<int, int>> dq;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    dq.emplace_back(start[0], start[1]);
    dist[start[0]][start[1]] = 0;
    while (!dq.empty()) {
        auto [x, y] = dq.front(); dq.pop_front();
        if(visited[x][y]) continue;
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
            int dis = 0;
            if(matrix[x][y] == dirs_c[i]) {
                dis = dist[x][y] + 0;
                dq.emplace_front(nx, ny);
            } else {
                dis = dist[x][y] + 1;
                dq.emplace_back(nx, ny);
            }
            if(dist[nx][ny] > dis) dist[nx][ny] = dis;
        }
    }
    return dist[end[0]][end[1]];
}