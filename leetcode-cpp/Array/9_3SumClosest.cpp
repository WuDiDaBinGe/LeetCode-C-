#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    int result=0;
    int gap=9999;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-2;i++){
        if(i>0 && nums[i]==nums[i-1])
            continue;
        int left=i+1,right=nums.size()-1;
        while(left<right)
        {
            int current_sum = nums[left]+nums[right]+nums[i];
            int current_gap = abs(current_sum-target);
            if(current_gap<gap)
            {
                gap=current_gap;
                result=current_sum;
            }
            if(current_sum==target)
            {
                result=current_sum;
                gap=0;
                return result;
            }
            else if(current_sum<target)
                left++;
            else
                right--;
        }
    }
    return result;
}
int main()
{
    vector<int> nums={-1,2,1,-4};
    cout<<threeSumClosest(nums,1);
    return 0;
}