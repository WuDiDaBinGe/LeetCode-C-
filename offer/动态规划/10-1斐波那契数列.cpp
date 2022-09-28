#include<bits/stdc++.h>
using namespace std;
class Solution {
    const int MOD = 1e9 + 7;
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        vector<vector<long>> help = {{1, 1}, {1, 0}};
        vector<vector<long>> res = pow(help, n - 1);
        return res[0][0];
    }
    vector<vector<long>> pow(vector<vector<long>> x, int n) {
        vector<vector<long>> res = {{1, 0}, {0, 1}};
        while(n >0) {
            if(n&1) res = mul(res, x);
            x = mul(x, x);
            n = n >> 1;
        }
        return res;
    }
    vector<vector<long>> mul(vector<vector<long>> x, vector<vector<long>> y) {
        vector<vector<long>> res = {{0, 0}, {0, 0}};
        for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
        for(int k = 0; k < 2; ++k) {
            res[i][j] += x[i][k] * y[k][j];
            res[i][j] = res[i][j] % MOD;
        }
        return res;
    }
};