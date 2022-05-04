#include<bits/stdc++.h>
using namespace std;
// 使用备忘录+dfs的方法
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> result;
    int m, n;
    int dfs(int x, int y, vector<vector<int>>& matrix) {
        if(result[x][y] != 0) return result[x][y];
        int res = INT_MIN;
        result[x][y]++;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[nx][ny] <= matrix[x][y]) continue;
            result[x][y] = max(result[x][y], dfs(nx, ny, matrix) + 1);
        }
        //cout<<x<<" "<<y<<" "<<result[x][y]<<endl;
        return result[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        result = vector<vector<int>>(m, vector<int>(n, 0));
        int res = INT_MIN;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res = max(res, dfs(i, j, matrix));
            }
        }
        return res;
    }
};
// 使用拓扑排序思想:有向图 小->大
// 剔除出度为0的节点 看看有几层topo排序 类似于层次遍历
int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int res = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> outDgree(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < 4; ++k) {
                int nx = i + dirs[k][0], ny = j + dirs[k][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny <n && matrix[nx][ny] > matrix[i][j]) outDgree[i][j]++;
            }
        }
    } 
    queue<pair<int, int>> q;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(outDgree[i][j] == 0) q.push(make_pair(i, j));
        }
    }
    while(!q.empty()) {
        int count = q.size();
        for(int i = 0; i < count; ++i) {
            auto out = q.front(); q.pop();
            for(int k = 0; k < 4; ++k) {
                int nx = out.first + dirs[k][0], ny = out.second + dirs[k][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny <n && matrix[nx][ny] < matrix[out.first][out.second]) {
                    outDgree[nx][ny]--;
                    if(outDgree[nx][ny] == 0) q.push(make_pair(nx, ny));
                } 
                
            }
        }
        res++;
}

return res;
}
int main() {
    return 0;
}