#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;
    int movingCount(int m, int n, int k) {
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        return dfs(0, 0, k, m, n);
    }
    int dfs(int x, int y, int k, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n || canGet(x, y) > k || visited[x][y]) return 0;
        visited[x][y] = true;
        int res = 1;
        for(int i = 0; i < 4; i++) {
            int  nx = x + dirs[i][0], ny = y + dirs[i][1];
            res += dfs(nx, ny, k, m, n);
        }
        return res;
    }
    int canGet(int x, int y) {
        int res = 0;
        while(x) {
            res += x % 10;
            x = x / 10;
        }
        while(y) {
            res += y % 10;
            y = y / 10;
        }
        return res;
    }
};

// bfs
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}};
    int bitssum(int x, int y){
        int sum = 0;
        while(x) {
            sum += x % 10;
            x = x / 10;
        }
        while(y) {
            sum += y % 10;
            y = y / 10;
        }
        return sum;
    }
    int movingCount(int threshold, int rows, int cols) {
        int res = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()){
            auto pos = q.front();q.pop();
            int x = pos.first, y = pos.second;
            res++;
            for(int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols || bitssum(nx, ny) > threshold || visited[nx][ny]) continue;
                q.push({nx, ny});
                // 看frontier中是否有重复
                visited[nx][ny] = true;
            }
        }
        return res;
    }
};