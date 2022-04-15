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
void dfs(int index, vector<int>& nums) {
    cout<<index<<endl;
    // valid border 
    if(index == nums.size()) {
        if(res == "") res = path;
        else if(res != ""){
            if(isValidSQ(res, path)) {
                res = path;
            }
        }
        return ;
    }
    // purne
    
    // make choice
    for(int i = 0; i < nums.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        string n = to_string(nums[i]);
        int size = n.size();
        path += n;
        dfs(index + 1, nums);
        visited[i] = false;
        while (size--) {
            path.pop_back();
        }
    }
}
string minNumber(vector<int>& nums) {
    visited = vector<bool>(nums.size(), false);
    dfs(0, nums);
    return res;
}
bool cmp(string a, string b) {
    return !isValidSQ(a + b, b + a);
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
int main() {
    vector<int> nums = {0,9,8,7,6,5,4,3,2,1};
    cout<<minNumber1(nums)<<endl;
    return 0;
}