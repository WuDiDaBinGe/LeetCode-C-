#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
    int n; cin>>n;
    vector<int> nums(n, 0);
    // 使用前缀和优化
    vector<int> prefixRed(n + 1, 0), predfixPur(n + 1, 0);
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    string s;cin>>s;
    long long reds = 0, purs = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i - 1] == 'R') {
            prefixRed[i] = prefixRed[i - 1] + nums[i -1];
            predfixPur[i] = predfixPur[i - 1];
        } else{
            predfixPur[i] = predfixPur[i - 1] + nums[i - 1];
            prefixRed[i] = prefixRed[i - 1];
        }
        cout<<prefixRed[i]<<" "<<predfixPur[i]<<endl;
    }
    int q; cin>>q;
    for(int i = 0; i < q; i++) {
        int days; cin>>days;
        int turn = days / n;
        long long a = turn * prefixRed[n], b = turn * predfixPur[n];
        days = days % n;
        a += prefixRed[days];
        b += predfixPur[days];
        // for(int d = 0; d < days; d++) {
        //     if(s[d] == 'R') {
        //         a += nums[d];
        //     } else{
        //         b += nums[d];
        //     }
        // }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}