#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin>>n>>k;
    vector<long long> nums(n);
    for(int i = 0; i < n; ++i) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end()); 
    reverse(nums.begin(), nums.end());
    // 滑动窗口 
    long long sum = 0;
    //sum * k < nums[i] * count
    int left = 0, right = 0,  count = 0;
    int res = 0;
    while(right < n) {
        sum += nums[right];
        count++;
        right++;
        while(left <= right && sum * k < nums[right - 1] * count) {
            sum -= nums[left];
            left++;
            count--;
        }
        res = max(count, res);
    }
    cout<<res<<endl;
    return 0;
}