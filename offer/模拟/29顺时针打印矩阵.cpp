#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if(n == 0) return res;
        int m = matrix[0].size();
        if(m == 0) return res;
        int ex = n -1, ey = m - 1;
        // 向上取整
        int turn = min((n - 1) / 2 + 1, (m - 1) /2 + 1);
        int i = 0;
        while (i <= ex && i <= ey) {
            //向右 必须走
            for(int j = i; j <= ey; j++ )
                res.push_back(matrix[i][j]);
            //向下 至少有两行 才能向下走
            if(i < ex) {
                for(int j = i + 1; j <= ex; j++) {
                    res.push_back(matrix[j][ey]);
                }
            }
            //至少有 两行两列才能向左右
            if(i < ey && i < ex) {
                for(int j = ey - 1; j >= i; j--) {
                    res.push_back(matrix[ex][j]);
                }
            }
            //至少有 两列 三行才可以向上走
            if(1 < ex - i && i < ey) {
                for(int j = ex - 1; j > i; j--) {
                    res.push_back(matrix[j][i]);
                }
            }
            ex--;
            ey--;
            i++;
        }
        return res;
    }
};
int main() {
    return 0;
}