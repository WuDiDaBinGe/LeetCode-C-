#include<bits/stdc++.h>
using namespace std;
// 优先队列
vector<int> getLeastNumbers(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < arr.size(); ++i) {
        pq.push(arr[i]);
    }
    vector<int> res;
    while(k--){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
// 快速排序
// 还有BUG 需要调整
vector<int> getLeastNumbers1(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, right = n - 1;
    int target = n - k;
    while(left < right) {
        int flag = arr[rand() % (right - left + 1) + left];
        vector<int> border = partition(left, right, arr, flag);
        // 这里不等target不能等于左边界 左边界可能不是最大的。
        if(border[0] < target && border[1] >= target) {
            break;
        } else if(target <= border[0]) {
            right = border[0];
        } else if(target >= border[1]) {
            left = border[1];
        }
    }
    vector<int> res;
    for(int i = arr.size() - 1; i >= target; i--) {
        res.push_back(arr[i]);
    }
    return res;
}
// partition操作
vector<int> partition(int left, int right, vector<int>& nums, int flag) {
    int l = left - 1 , r = right + 1;
    int cur = left;
    while (cur < r) {
        if(nums[cur] < flag) {
            swap(nums[cur], nums[l + 1]);
            l++;
            cur++;
        } 
        else if(nums[cur] == flag) {
            cur++;
        }
        else if(nums[cur] > flag)  {
            swap(nums[cur], nums[r - 1]);
            r--;
        }
    }
    return {left, right};
}
int main() {
    return 0;
}