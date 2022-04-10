#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string path="";
    vector<string> res;
    vector<bool> visited;
    vector<string> permutation(string s) {
        visited = vector<bool>(s.size(), false);
        sort(s.begin(), s.end());
        dfs(0, path, s);
        return res;
    }
    void dfs(int count, string& path, string& s) {
        if(count == s.size()) {
            cout<<path<<endl;
            res.push_back(path);
            return;
        } 
        for(int i = 0; i < s.size(); i++) {
            // 注意判重 相同的元素 必须填入从左到右未被选择的第一个元素
            if(visited[i] || (i > 0 && !visited[i - 1] && s[i - 1] == s[i])) {
                continue;
            } 
            visited[i] = true;
            path.push_back(s[i]);
            dfs(count + 1, path, s);
            visited[i] = false;
            path.pop_back();
        }
    }
};
int main() {
    Solution* a =new Solution();
    a->permutation("aba");
    return 0;
}