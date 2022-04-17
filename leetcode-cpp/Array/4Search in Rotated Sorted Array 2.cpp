#include<iostream>
#include<vector>
using namespace std;
/*
    与上一题相比增加了重复的元素
*/
int search(vector<int>& nums, int target){
    int first=0, end=nums.size()-1;
    while(first<=end){
        int mid = (first+end) /2;
        if(nums[mid]==target) return mid;
        // [first,mid] order
        if(nums[first]<=nums[mid]){
            // target in [first,mid]
            if(target>=nums[first] && target<=nums[mid]){
                end = mid-1;
            }
            // target  not in [first,mid]
            else{
                first = mid+1;
            }
        }
        // [first,mid] unorder [mid,end] order
        else{
            //target in [mid,end]
            if(target>=nums[mid]&&target<=nums[end]){
                first = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {3,1};
    cout<<search(nums,1)<<endl;
    return 0;
}