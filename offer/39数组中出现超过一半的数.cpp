#include<bits/stdc++.h>
using namespace std;
// 1.哈希表计数
// 2.sort + 取中间
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return nums[n / 2];
}
// 3.摩尔投票法
int majorityElement2(vector<int>& nums) {
    int n = nums.size();
    int vote = 0, x = nums[0];
    for(int i = 0; i < n; i++) {
        if(vote == 0) x = nums[i];
        if(nums[i] == x)
            vote++;
        else 
            vote--;
    }
    return x;
}
int main(){
    return 0;
}