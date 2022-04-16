#include<bits/stdc++.h>
using namespace std;
//归并排序
int merge(vector<int>& nums, int left, int right, int mid) {
    vector<int> temp;
    int l = left, r = mid + 1;
    int res = 0;
    while (l <= mid && r <= right) {
        if(nums[l] <= nums[r]) {
            temp.push_back(nums[l]);
            l++;
        }
        else if(nums[l] > nums[r]) {
            temp.push_back(nums[r]);
            res += (mid - l + 1);
            r++;
        }
    }
    while (l <= mid) {
       temp.push_back(nums[l]);
       l++;
    }
    while (r <= right) {
        temp.push_back(nums[r]);
        res += (mid - l + 1);
        r++;
    }
    copy(temp.begin(), temp.end(), nums.begin() + left);
    return res;
}
int mergeSort(vector<int>& nums, int left, int right) {
    if(left == right)   return 0;
    int mid = (right + left)>>1;
    return mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right) + merge(nums, left, right, mid);
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    if(n == 1 || n == 0) return 0; 
    return mergeSort(nums, 0, n - 1);
}
// 离散化树状数组

int main() {
    vector<int> nums = {7, 5,  6, 4};
    cout<<reversePairs(nums)<<endl;
    cout<<endl;
    for(int i = 0; i < nums.size(); i++) {
        cout<<nums[i]<<" ";
    }
    return 0;
}