#include<iostream>
#include<vector>
#include <iterator>
#include <cassert>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int index =0;
        for(int i=0;i<nums.size();i++){
            if(nums[index] != nums[i]){
                nums[++index] = nums[i];
            }
        }
        return index+1;
    }
    int removeDuplicates1(vector<int>& nums){
        return distance(nums.begin(),unique(nums.begin(),nums.end()));
    }
};