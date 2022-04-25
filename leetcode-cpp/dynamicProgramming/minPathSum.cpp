#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> world;
    vector<vector<int>> memorizes;
    // 备忘录算法
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        world = grid;
        // 初始化备忘录
        memorizes = vector<vector<int>>(n, vector<int>(m, 0));
        memorizes[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            memorizes[i][0] =grid[i][0] + memorizes[i - 1][0]; 
        }
        for(int j = 1; j < m; j++) {
            memorizes[0][j] = grid[0][j] + memorizes[0][j - 1];
        }
        return dp(n - 1, m -1);
    }
    int dp(int i, int j) {
        //递归的base case
        if(i == 0 || j == 0) return memorizes[i][j];
        // 优化解决重叠子问题 若在备忘录中存在
        if(memorizes[i][j] != 0) return memorizes[i][j];
        // 给备忘录赋值 寻找递推公式
        memorizes[i][j] = min(dp(i - 1, j), dp(i, j -1)) + world[i][j];
        return memorizes[i][j];
    }
};
int main(){
    return 0;
}