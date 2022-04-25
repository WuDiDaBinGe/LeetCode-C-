#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k, l = 0, r = n - 1;
        while(l < r) {
            int flag = nums[n % (r - l + 1) + l];
            auto gap = partition(nums, l, r, flag);
            if(gap[0] < target && target < gap[1])
                return nums[target];
            else if(gap[0] >= target) {
                r = gap[0];
            } 
            else if(gap[1] <= target) {
                l = gap[1];
            }
        }
        return nums[l];
    }
    vector<int> partition(vector<int>& nums, int l, int r, int flag) {
        int left = l - 1, right = r + 1, cur = l;
        while(cur < right) {
            if(nums[cur] < flag) {
                swap(nums[left + 1], nums[cur]);
                cur++;
                left++;
            }
            else if(nums[cur] == flag)
                cur++;
            else if(nums[cur] > flag) {
                swap(nums[cur], nums[right - 1]);
                right--;
            }
        }
        return vector<int>{left, right};
    }
};
int main() {
    return 0;
}