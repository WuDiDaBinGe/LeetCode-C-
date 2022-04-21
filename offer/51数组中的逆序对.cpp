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
// 离散化 + 树状数组
struct BIL{
    vector<int> tree;
    BIL(int n) {
        tree = vector<int>(n + 1);
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int index, int k) {
        while (index <= tree.size()) {
            tree[index] += k;
            index += lowbit(index);
        }
    }
    int ask(int index) {
        int res = 0;
        while(index > 0) {
            res += tree[index];
            index -= lowbit(index);
        }
        return res;
    }
};
int reversePairs1(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    // 将原数组转化成排名的形式
    for(int& a:nums) {
        a = lower_bound(temp.begin(), temp.end(), a) - temp.begin() + 1;
    }
    BIL bil(n);
    int ans = 0;
    for(int i = n - 1; i >= 0; --i) {
        ans += bil.ask(nums[i] - 1);
        bil.add(nums[i], 1);
    }
    return ans;
}
int main() {
    vector<int> nums = {2,4,3,5,1};
    cout<<reversePairs(nums)<<endl;
    vector<int> nums1 = {2,4,3,5,1};
    cout<<reversePairs1(nums1)<<endl;
    return 0;
}