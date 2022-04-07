#include<bits/stdc++.h>
using namespace std;
#define MAXNUM 100010
int X[MAXNUM];
int main(){
    int n; cin>>n;
    for(int i = 1; i <= n; i++) {
        int t;
        cin>>X[i]>>t;
    }
    sort(X + 1, X +  n + 1);
    // 找中位数
    int flag = X[(n + 1) / 2];
    long long res = 0;
    for(int i = 1; i <= n; ++i) {
        res += abs(flag - X[i]);
    }
    cout<<res<<endl;
    return 0;
}