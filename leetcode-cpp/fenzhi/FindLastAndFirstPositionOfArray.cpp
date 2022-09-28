#include<vector>
#include<iostream>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    vector<int> res;
    //search left  bounder
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            right = mid - 1;
        }
        else if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
    }
    if(left >= nums.size() || nums[left] != target) {
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    res.push_back(left);
    left = 0; right = nums.size() -1;
    // search right bounder
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            left = mid + 1;
        }
        else if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
    }        
    if(right < 0 || nums[right] != target) {
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    res.push_back(right);
    return res;
}
int main() {
    vector<int> array = {5,7,7,8,8,10};
    vector<int> temp = searchRange(array, 8);
    cout<<temp[0]<<" "<<temp[1]<<endl;
    return 0;
}