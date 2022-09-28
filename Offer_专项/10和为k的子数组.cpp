#include<bits/stdc++.h>
using namespace std;
// 前缀和 + 哈希表
// 以i为结尾用map记录前面有多少prefix[j]
// prefix[i] - prefix[j] = k => prefix[i] - k = prefix[j] 
int subarraySum(vector<int>& nums, int k) {
    int res = 0, n = nums.size();
    for(int i = 1; i < n; ++i) {
        nums[i] = nums[i] + nums[i - 1];
    }
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i < n; ++i) {
        int count = mp[nums[i] - k];
        res += count;
        mp[nums[i]]++;
    }
    return res;
}