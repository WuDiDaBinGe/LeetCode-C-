#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

/*
    space: O(mn)
*/
void setZeroes(vector<vector<int>>& matrix) {
    int n_r = matrix.size();
    int n_c = matrix[0].size();
    vector<bool> cols(n_c,false);
    vector<bool> rows(n_r,false);
    for (int i=0;i<n_r;i++) 
        for (int j = 0; j < n_c; j++)
            if (matrix[i][j] == 0) {
                cols[j]=true;
                rows[i]=true;
            }
    for (int i = 0; i < n_r; i++)
    {
        if (rows[i]==true) {
            for (int j=0;j<n_c;j++)
                matrix[i][j]=0;
        }
    }
    for (int i = 0; i < n_c; i++)
    {
        if (cols[i] == true) {
            for (int j=0;j<n_r;j++)
                matrix[j][i]=0;
        }
    }
}

/*
    Space : O(1)
    思路将第一行、第一列作为标志位，
    要记录第一行第一列之前是否存在0
*/
void setZeroes1(vector<vector<int>>& matrix) {
    int n_r = matrix.size();
    int n_c = matrix[0].size();
    bool first_row_f = false;
    bool first_col_f = false;
    // 记录第一列是否有0
    for (size_t i = 0; i < n_r; i++) {
        if (matrix[i][0] == 0) {
            first_col_f =true;
            break;
        }
    }
    // 记录第一行是否有0
    for (size_t i = 0; i < n_c; i++) {
        if (matrix[0][i] == 0) {
            first_row_f =true;
            break;
        }
    }
    // 修改标记位
    for (size_t i = 1; i < n_r; i++) {
        for (size_t j = 1; j < n_c; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // 根据标值位置 修改矩阵的值
    for (size_t i = 1; i < n_r; i++) {
        for (size_t j = 1; j < n_c; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    // 第一行 或者 第一列 置 0 
    if (first_col_f) {
        for (size_t i = 0; i < n_r; i++)
            matrix[i][0] = 0;
    }
    if (first_row_f) {
        for (size_t i = 0; i < n_c; i++)
            matrix[0][i] = 0;
    }
}

int main() {
    vector<vector<int>> a = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes1(a);
    for (int i=0;i<3;i++) 
        for (int j = 0; j < 3; j++)
            cout<<a[i][j]<<endl;
    return 0;
}