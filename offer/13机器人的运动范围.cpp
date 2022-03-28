#include<iostream>
#include<vector>
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