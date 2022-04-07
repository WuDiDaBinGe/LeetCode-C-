#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    vector<int> weights(n, 0);
    for(int i = 0; i < n; i++){
        cin>>weights[i];
    }
    sort(weights.begin(), weights.end());
    vector<int> small, bigger;
    for(int i = 0; i < n; i++) {
        if(i < n / 2) small.push_back(weights[i]);
        else bigger.push_back(weights[i]);
    }
    vector<int> ans;
    reverse(bigger.begin(), bigger.end());
    int sindex = 0, bindex = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            ans.push_back(bigger[bindex]);
            bindex++;
        } else {
            ans.push_back(small[sindex]);
            sindex++;
        }
    }
    long long res = abs(ans[0] - ans[n - 1]);
    for(int i = 1; i < n; i++) {
        res += abs(ans[i] - ans[i - 1]);
    }
    cout<<res<<endl;
    for(int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}