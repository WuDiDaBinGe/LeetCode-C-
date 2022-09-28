#include<bits/stdc++.h>
using namespace std;
/*长城*/
int solve(vector<int>& odd, vector<int>& ji){
    sort(odd.begin(), odd.end());
    int n = odd.size(), ret = 0, x = odd[n / 2];
    for(int i = 0; i < n;++i) {
        ret += abs(odd[i] - x);
    }

    sort(ji.begin(), ji.end());
    int nj = ji.size(), retj = 0, xj = ji[nj / 2];
    if(x == xj) {
        xj = *upper_bound(ji.begin(), ji.end(), xj);
    }
    for(int i = 0; i < nj; ++i) {
        ret += abs(ji[i] - xj);
    }
    return ret;
}
int main(){
    int T;cin>>T;
    while(T--) {
        int n; cin>>n;
        vector<int> nums(n);
        vector<int> odd, ji;
        for(int i = 0; i < n; ++i) {
            cin>>nums[i];
            if(i % 2) ji.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        cout<<solve(odd, ji)<<endl;

    }
    return 0;
}