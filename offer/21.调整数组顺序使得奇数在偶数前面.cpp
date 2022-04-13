#include<bits/stdc++.h>
using namespace std;
//partition操作
vector<int> exchange(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums;
    partion(0, n - 1, nums);
    return nums;
}
void partion(int left, int right, vector<int>& nums) {
    int l = left - 1, r = right + 1;
    int cur = left;
    while(cur < r) {
        if(nums[cur] % 2) {
            swap(nums[cur], nums[l + 1]);
            l++;
            cur++;
        } else {
            swap(nums[cur], nums[r - 1]);
            r--;
        }
    }
}
//双指针
vector<int> exchange(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        // 左边指针找奇数
        while(left < n && nums[left] & 1 == 1) left++;
        // 右边指针找偶数
        while(right >= 0 && nums[right] & 1 == 0) right++;
        swap(nums[left], nums[right]);
    }
    return nums;
}
int main() {
    return 0;
}
