#include<bits/stdc++.h>
using namespace std;
// N皇后问题
bool isValid(vector<int> C, int row, int col) {
    for(int i = 0; i < row; i++) {
        if(C[i] == col) return false;
        if(abs(i - row) == abs(C[i] - col)) return false;
    }
    return true;
}
void dfs(vector<int>& C, int& res, int row, int n){
    if(row == n) {
        res++;
        return;
    }
    for(int j = 0; j < n; j++) {
        bool flag = isValid(C, row, j);
        if(!flag) continue;
        C[row] = j;
        dfs(C, res, row + 1, n);
        C[row] = -1;
    }

}
int buildHouses(int n) {
    int res = 0;
    vector<int> C(n, -1);
    dfs(C, res, 0, n);
    return res;
}
int main() {
    cout<<buildHouses(4)<<endl;
    return 0;
}