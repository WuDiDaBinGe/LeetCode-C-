#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        //cout<<n<<endl;
        int row = 0, col = m - 1;
        while(row < n && col >= 0) {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target) {
                row++;
            }
            else if(matrix[row][col] > target) {
                col--;
            }
            //cout<<row<<" "<<col<<endl;
        }
        return false;
    }
};