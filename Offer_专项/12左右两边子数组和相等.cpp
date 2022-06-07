#include<bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        nums[i] = nums[i] + nums[i - 1];
    }
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            if(nums[n - 1] - nums[0]== 0) return 0;
        }
        else if(i == n - 1) {
            if(nums[i - 1] == 0) return n - 1;
        } else {
            int left = nums[i - 1];
            int right = nums[n - 1] - nums[i];
            if(left == right) return i;
        }
    }
    return -1;
}
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        // 数组的总和
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
int main()
{
   
   return 0;
}