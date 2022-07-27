#include<bits/stdc++.h>
using namespace std;
// 前缀和 + 哈希表
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> windows;
    int n = nums.size();
    int res = INT_MIN;
    vector<int> prefix(n);
    prefix[0] = nums[0] == 0?-1:1;
    for(int i = 1; i < n; ++i) {
        if(nums[i] == 1) {
            prefix[i] = prefix[i - 1] + 1;
        } else {
            prefix[i] = prefix[i - 1] - 1;
        }   
    }
    unordered_map<int, int> mp;
    mp[0] = -1;
    for(int i = 0; i < n; ++i) {
        int key = prefix[i];
        if(mp.find(key) != mp.end()) {
            res = max(res, i - mp[key]);
        } else {
            mp[key] = i;
        }
    }
    return res == INT_MIN ? 0 : res;
}
int main()
{
   
   return 0;
}