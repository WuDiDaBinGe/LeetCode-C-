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
vector<int> getLeastNumbers1(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, right = n - 1;
    while(left < right) {
        int flag = arr[rand() % (right - left + 1) + left];
        vector<int> border = partition(left, right, arr, flag);
        if(border[0] <= n - k && border[1] >= n - k) {
            break;
        } else if(n - k < border[0]) {
            right = left;
        } else if(n - k > border[1]) {
            left = right;
        }
    }
    vector<int> res;
    for(int i = arr.size(); i >= n - k; i--) {
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