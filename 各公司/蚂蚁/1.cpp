#include<bits/stdc++.h>
using namespace std;
/*矩阵中的二分*/
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if(n == 0) return false;
    int m = matrix[0].size();
    if(m == 0) return false;
    //cout<<n<<endl;
    // 左下角
    int row = n - 1, col = 0;
    while(row >= 0 && col < m) {
        if(matrix[row][col] == target)
            return true;
        else if(matrix[row][col] < target) {
            col++;
        }
        else if(matrix[row][col] > target) {
            row--;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<findNumberIn2DArray(m, 10)<<endl;
    return 0;
}