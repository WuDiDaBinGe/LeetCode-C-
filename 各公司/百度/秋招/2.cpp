#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<int> as(n);
    vector<int> bs(m);
    vector<long long> prefixa(n + 1), prefixb(m + 1);
    for(int i = 1; i <= n; ++i) {
        cin>>as[i - 1];
        prefixa[i] = prefixa[i - 1] + as[i - 1];
    }
    for(int j = 1; j <= m; ++j) {
        cin>>bs[j - 1];
        prefixb[j] = prefixb[j - 1] + bs[j - 1];
    }
    int res = INT_MIN;
    for(int i = 0; i <= n; ++i){
        int r = i;
        long long remain_t = t - prefixa[i];
        if(remain_t < prefixb[1]) {
            res = max(res, i - 1);
            break;
        }
        auto iter = lower_bound(prefixb.begin(), prefixb.end(), remain_t);
        if(iter == prefixb.end()) {
            r += m;
        }
        else if(*iter == remain_t) {
            r += (iter - prefixb.begin());
        }
        else{
            r += (iter - prefixb.begin() - 1);
        }
        res = max(res, r);
    }
    cout<<res<<endl;
    return 0;
}