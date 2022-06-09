#include<bits/stdc++.h>
using namespace std;
class NumMatrix {
public:
    // 一维的前缀和
    vector<vector<int>> matrix;
    vector<vector<int>> prefix_row;
    NumMatrix(vector<vector<int>>& matrix) {
        matrix = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        prefix_row = vector<vector<int>>(m, vector<int>(n, 0));
        // base case
        for(int i = 0; i < m; ++i) 
            prefix_row[i][0] = matrix[i][0];
        for(int i = 0; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                prefix_row[i][j] = matrix[i][j] + prefix_row[i][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i = row1; i <= row2; ++i) {
            int a = col1 == 0 ? 0 : prefix_row[i][col1 - 1];
            int b = prefix_row[i][col2];
            res += (a - b);
        }
        return res;
    }
};
class NumMatrix1 {
public:
    // 一维的前缀和
    vector<vector<int>> matrix;
    vector<vector<int>> prefixs;
    NumMatrix1(vector<vector<int>>& matrix) {
        matrix = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        prefixs = vector<vector<int>>(m, vector<int>(n, 0));
        // base case
        prefixs[0][0] = matrix[0][0];
        // 第一行
        for(int j = 1; j < n; ++j) 
            prefixs[0][j] = prefixs[0][j - 1] + matrix[0][j];
        // 第一列
        for(int i = 1; i < m; ++i) 
            prefixs[i][0] = prefixs[i-1][0] + matrix[i][0];
        // 二维前缀和
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                prefixs[i][j] = matrix[i][j] + prefixs[i][j - 1] + prefixs[i - 1][j] - prefixs[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0, topArea = 0, leftArea = 0, topleftArea = 0;
        topArea = row1 >= 1 ? prefixs[row1 - 1][col2] : 0;
        leftArea = col1 >= 1 ? prefixs[row2][col1 - 1] : 0;
        topleftArea = row1 >= 1 && col1 >= 1 ? prefixs[row1 - 1][col1 - 1] : 0;
        res = prefixs[row2][col2] - topArea - (leftArea - topleftArea);
        return res;
    }
};
int main()
{
   
   return 0;
}