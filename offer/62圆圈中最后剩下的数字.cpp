#include<bits/stdc++.h>
using namespace std;
// 约瑟夫环的问题
// dp
int lastRemaining(int n, int m) {
    int dp = 0;
    for(int i = 2; i < n; i++) {
        dp = (dp + m) % i;
    }
    return dp;
}
// 模拟超时 
int lastRemaining(int n, int m) {
    vector<int> nums;
    for(int i = 0; i < n; i++)
        nums.push_back(i);
    int i  = 0;
    while(nums.size() > 1) {
        int count = m;
        int j;
        for(j = i; count > 1; j = (j + 1) % nums.size()) {
            count--;
        }
        nums.erase(nums.begin() + j);
        i = j;
    }
    return nums[0];
}
int main() {
    cout<<lastRemaining(70866, 116922)<<endl;
    return 0;
}