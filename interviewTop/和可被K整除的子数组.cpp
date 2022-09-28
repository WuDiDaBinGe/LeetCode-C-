#include<bits/stdc++.h>
using namespace std;
/*
数论中的重要概念。给定一个正整数m，如果两个整数a和b满足a-b能够被m整除，即(a-b)/m得到一个整数，那么就称整数a与b对模m同余，
记作a≡b(mod m)。对模m同余是整数的一个等价关系
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> mp = {{0, 1}};
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正 必须要修正
            int modulus = (sum % k + k) % k;
            res += mp[modulus];
            mp[modulus]++;
        }
        return res;
    }
};
int main(){
    return 0;
}