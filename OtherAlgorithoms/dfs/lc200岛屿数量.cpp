#include<iostream>
#include<vector>
using namespace std;
int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    if(x < 0 || x >= n) return;
    if(y < 0 || y >= m) return;
    cout<<x<<" "<<y<<endl;
    // make choices
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if(nx >=0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '0') {
            dfs(nx, ny, grid, visited);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1' && !visited[i][j] ){
                dfs(i, j, grid, visited);
                res += 1;
            }
        }
    }
    return res;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','1','0'},
        {'0','0','0','1','1'}};
    cout<<numIslands(grid);
    return 0;
}