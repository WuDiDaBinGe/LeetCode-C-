#include<bits/stdc++.h>
using namespace std;
vector<int> path;
vector<vector<int>> res;
vector<bool> visited;
void dfs(int step, int gap, vector<int>& candidates) {
    // border
    if(step == candidates.size()) {
        if(gap == 0) {
            res.push_back(path);
        }
        return;
    }
    // valid
    if(gap == 0) {
        //cout<<"满足"<<endl;
        res.push_back(path);
        return;
    }
    //purne
    if(candidates[step] > gap) return;
    //cout<<"index:"<<step<<" "<<candidates[step]<<" "<<gap<<endl;
    // choice
    bool flag = step > 0 && (candidates[step] != candidates[step - 1] || (candidates[step] == candidates[step - 1] && visited[step - 1]));
    if(flag || step == 0) {
        visited[step] = true;
        path.push_back(candidates[step]);
        dfs(step + 1, gap - candidates[step], candidates);
        path.pop_back();
        visited[step] = false;
    }
    // no choice
    dfs(step + 1, gap, candidates);
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    visited = vector<bool>(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    dfs(0, target, candidates);
    return res;
}
int main() {
    vector<int> test = {10,1,2,7,6,1,5};
    combinationSum2(test, 8);
    cout<<res.size()<<endl;
    return 0;
}