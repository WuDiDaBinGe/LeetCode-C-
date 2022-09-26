#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    // 寻找左边界
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) {
            r = mid - 1;
        }
        else if(nums[mid] < target) {
            l = mid + 1;
        }
        else if(nums[mid] > target) {
            r = mid - 1;
        }
    }
    int left = l;
    // 寻找右边界
    l = 0, r = n -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(target == nums[mid])
            l = mid + 1;
        else if(nums[mid] < target)
            l = mid + 1;
        else if(nums[mid] > target) 
            r = mid - 1;
    }
    return r - left + 1;
}
int main() {
    vector<int> nums = {5,7,7,8,8,10};
    cout<<search(nums, 8)<<endl;
    cout<<search(nums, 6)<<endl;
    return 0;
}