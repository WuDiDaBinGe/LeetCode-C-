#include<bits/stdc++.h>
using namespace std;
vector<int> constructArr(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for(int i = 1; i < a.size(); i++) {
        dp[0] *= a[i];
    }        
    for(int i = 1; i < n; i++) {
        if(a[i] != 0)
            dp[i] = dp[i - 1] * a[i - 1] / a[i];
        else {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                dp[i] *= a[j];
            }
        }
    }
    return dp;
}
// 题解方法： 先乘下三角 后乘上三角
vector<int> constructArr1(vector<int>& a) {
    int n = a.size();
    if(n == 0) return {};
    int temp = 1;
    vector<int> B(n, 1);
    // 乘下三角
    for(int i = 0; i < n; ++i) {
        B[i] *= temp;
        temp *= a[i];
    }
    temp = 1;
    // 上三角
    for(int i = n - 1; i >= 0; --i) {
        B[i] *= temp;
        temp *= a[i];
    }
    return B;
}
int main() {
    return 0;
}