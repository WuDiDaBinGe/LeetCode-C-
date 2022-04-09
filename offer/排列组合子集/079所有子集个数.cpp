#include<bits/stdc++.h>
using namespace std;
vector<int> path;
vector<vector<int>> res;
void dfs(int index, vector<int>& nums) {
    if(index == nums.size()) {
        for(int i = 0; i < path.size(); i++) {
            cout<<path[i]<<" ";
        }
        cout<<endl;
        res.push_back(path);
        return ;
    }
    // 选
    path.push_back(nums[index]);
    dfs(index + 1, nums);
    path.pop_back();
    // 不选
    dfs(index + 1, nums);
}
vector<vector<int>> subsets(vector<int>& nums) {
    dfs(0, nums);
    return res;
}
// 其他思路
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        backtrack(nums, 0);
        return res;
    }
private:
    void backtrack(const vector<int>& nums, int start){
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            res.push_back(temp);
            backtrack(nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> res;
    vector<int> temp;
};

int main() {
    vector<int> a = {1,2,3};
    subsets(a);
    return 0;
}
