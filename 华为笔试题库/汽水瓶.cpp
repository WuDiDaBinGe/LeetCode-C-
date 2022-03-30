#include<iostream>
#include<vector>
using namespace std;
vector<int> dp(105, 0);
int getAns(int n) {
    if(n == 1)
        return 0;
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        int turn = i / 3;
        int yu = i % 3;
        dp[i] = turn + dp[turn + yu];
    }
    return dp[n];
}
int main() {
    while (true) {
        int n; cin>>n;
        if(n == 0) break;
        cout<<getAns(n)<<endl;
    }
    return 0;
}