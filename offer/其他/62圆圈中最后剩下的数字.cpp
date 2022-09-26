#include<bits/stdc++.h>
using namespace std;
// 约瑟夫环的问题 https://leetcode.cn/circle/article/BOoxAL/
// dp
int lastRemaining(int n, int m) {
    int dp = 0;
    for(int i = 2; i < n; i++) {
        dp = (dp + m) % i;
    }
    return dp;
}
// 模拟
int LastRemaining_Solution(int n, int m) {
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        nums.push_back(i);
    }
    int startIndex = 0;
    while (nums.size() > 1) {
        int delIndex = (startIndex + m - 1) % nums.size();
        nums.erase(nums.begin() + delIndex);
        startIndex = delIndex;
    }
    return nums[0];
}
int main() {
    cout<<LastRemaining_Solution(70866, 116922)<<endl;
    return 0;
}