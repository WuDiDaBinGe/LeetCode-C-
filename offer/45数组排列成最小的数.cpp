#include<bits/stdc++.h>
using namespace std;
string res = "";
string path = "";
vector<bool> visited;

// a >= b 返回 true
bool isValidSQ(string a, string b) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) continue;
        else if(a[i] > b[i]) return true;
        else return false;
    }
    return true;
}
// 使用内置排序函数
bool cmp(string a, string b) {
    return a + b < b + a;
}
string minNumber1(vector<int>& nums) {
    vector<string> snums;
    for(int i = 0; i < nums.size(); i++)
        snums.push_back(to_string(nums[i]));
    sort(snums.begin(), snums.end(), cmp);
    string res = "";
    for(int i = 0; i < snums.size(); i++){
        res += snums[i];
    }
    return res;
}
void quickSort(vector<string>& strs, int left, int right) {
    if(left >= right) return;
    int i = left, j = right;
    while(i < j) {
        while(strs[j] + strs[left] >= strs[left] + strs[j] && i < j) j--;
        while(strs[i] + strs[left] <= strs[left] + strs[i] && i < j) i++;
        swap(strs[i], strs[j]);
    }
    swap(strs[left], strs[i]);
    quickSort(strs, left, i - 1);
    quickSort(strs, i + 1, right);
    return;
}
// 使用快速排序
string minNumber2(vector<int>& nums) {
    vector<string> str_nums;
    for(int i = 0; i < nums.size(); i++)
        str_nums.push_back(to_string(nums[i]));
    quickSort(str_nums, 0, str_nums.size() - 1);
    string res = "";
    for(int i = 0; i < str_nums.size(); i++)
        res += str_nums[i];
    return res;
}
int main() {
    vector<int> nums = {0,9,8,7,6,5,4,3,2,1};
    cout<<minNumber2(nums)<<endl;
    return 0;
}