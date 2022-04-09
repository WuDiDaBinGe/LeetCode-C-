#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
vector<int> path;
vector<bool> visited;
void dfs(int step, vector<int>& nums) {
    if(step == nums.size()) {
        for(int i = 0; i < path.size(); i++) {
            cout<<path[i]<<" ";
        }
        cout<<endl;
        res.push_back(path);
        return;
    }
    // 不选
    dfs(step + 1, nums);
    // 选的时候应该排除重复
    // 避免重复选择
    bool flag = step > 0 && (nums[step] != nums[step - 1] || (nums[step] == nums[step - 1] && visited[step - 1]));
    if(flag || step == 0) {
        path.push_back(nums[step]);
        visited[step] = true;
        dfs(step + 1, nums);
        visited[step] = false;
        path.pop_back();
    }
    
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    visited = vector<bool>(nums.size(), false);
    dfs(0, nums);
    return res;
}
int main(){
    vector<int> a = {2};
    subsetsWithDup(a);
    return 0;
}