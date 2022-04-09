#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
vector<int> path;
vector<bool> visited;
void dfs(int index, vector<int>& nums) {
    if(index == nums.size()) {
        res.push_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(visited[i]) continue;
        path.push_back(nums[i]);
        visited[i] = true;
        dfs(index + 1, nums);
        path.pop_back();
        visited[i] = false;
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    visited = vector<bool>(nums.size(), false);
    dfs(0, nums);
    return res;
}
int main() {
    vector<int> test = {1};
    permute(test);
    cout<<res.size()<<endl;
    return 0;
}