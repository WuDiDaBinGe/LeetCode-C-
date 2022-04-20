#include<bits/stdc++.h>
using namespace std;
//O(n)
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(i != nums[i]) return i;
    }
    return -1;
}
//O(logn) 区间查找问题 找第一个 i != nums[i]的
int missingNumber1(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] != mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
int main() {
    vector<int> nums = {0,1,3,4,5,6,7,9};
    cout<<missingNumber1(nums)<<endl;
    return 0;
}