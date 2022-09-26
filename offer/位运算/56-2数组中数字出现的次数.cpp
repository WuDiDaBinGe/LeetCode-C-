#include<bits/stdc++.h>
using namespace std;
// 统计每一个每一位上出现的1的个数， 仅存在正数的情况
int singleNumber(vector<int>& nums) {
    vector<int> hash(32, 0);
    for(int num : nums) {
        int res = 0;
        while(num){
            if(num & 1 == 1) hash[res]++;
            num = num>>1;
            res++;
        }
    }
    int res = 0;
    for(int i = 0; i < 32; i++) {
        if(hash[i] % 3 == 1) res += pow(2, i);
    }
    return res;
}
// 存在负数的情况
int singleNumber(vector<int>& nums) {
    vector<int> hash(32, 0);
    for(int i = 0; i < nums.size(); i++) {
        int a = nums[i];
        int n = 0;
        // 注意n不越界
        while(a && n < 32) {
            if(a & 1 == 1) hash[n]++;
            a = a >> 1;
            n++;
        }
    }
    int res = 0;
    for(int i = 0; i < 32; i++) {
        // 使用位运算的方式 否则负数会存在溢出的问题
        if(hash[i] % 3 == 1) res = res | (1<<i);
    }
    return res;
}
int main() {
    vector<int> nums = {9,1,7,9,7,9,7};
    cout<<singleNumber(nums)<<endl;
    return 0;
}