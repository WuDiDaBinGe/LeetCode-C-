#include<bits/stdc++.h>
using namespace std;
// 能力值是越来越小的
int main() {
    int n; cin>>n;
    vector<int> idos(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        cin>>idos[i];
    }
    vector<int> dp(n + 1, 1);
    for(int i = n; i >= 0; --i) {
        if(idos[i] != 0) 
            dp[idos[i]] += dp[i];
    }
    for(int i = 1; i <= n; ++i) {
        cout<<dp[i]<<endl;
    }
    return 0; 
}