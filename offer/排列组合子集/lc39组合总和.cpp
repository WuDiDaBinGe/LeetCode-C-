#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
vector<int> path;
void dfs(int index, int gap, vector<int>& nums) {
    //border
    if(index == nums.size()) {
        if(gap == 0) res.push_back(path);
        return;
    }
    // valid
    if(gap == 0) {
        res.push_back(path);
        return;
    }
    int max_nums = gap / nums[index];
    for(int i = 0; i <= max_nums; i++) {
        int count = i;
        while(count--) {
            path.push_back(nums[index]);
        }
        dfs(index + 1, gap - i * nums[index], nums);
        count = i;
        while(count--) {
            path.pop_back();
        }   
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    dfs(0, target, candidates);
    return res;
}
int main() {
    vector<int> test = {2,3,5};
    combinationSum(test, 8);
    cout<<res.size()<<endl;
    return 0;
}