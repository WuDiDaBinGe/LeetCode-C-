#include<bits/stdc++.h>
using namespace std;
// 二维dp
int main() {
    int T;cin>>T;
    for(int t = 0; t < T; t++) {
        int n;cin>>n;
        int sum = 0;
        vector<int> nums(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cin>>nums[i];
            sum += nums[i];
        }
        int dp_max = nums[0];
        int dp_min = nums[0];
        int res = nums[0];
        for(int i = 2; i <= n; i++) {
            dp_max = max(nums[i], dp_max + nums[i]);
            dp_min = min(nums[i], dp_min + nums[i]);
            res = max(res, dp_max);
            res = max(res, sum - dp_min);
        }
        cout<<res<<endl;
    }
    return 0;
}