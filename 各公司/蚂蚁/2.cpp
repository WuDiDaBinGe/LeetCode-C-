#include<bits/stdc++.h>
using namespace std;
int findRepeatNumber(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int value = nums[i];
        if(value == i) continue;
        while(nums[i] != i){
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[nums[i]], nums[i]);
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {3,2,3,1,0,2,5,3};
    cout<<findRepeatNumber(nums)<<endl;
    return 0;
}