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
/*交换*/
class Solution {
  public:
    vector<string> res;
    void dfs(int h, string& str) {
        if (h == str.size()) {
            res.push_back(str);
            return;
        }
        set<char> st;
        for (int i = h; i < str.size(); ++i) {
            if(st.find(str[i]) != st.end()) continue;
            st.insert(str[i]);
            swap(str[h], str[i]);
            dfs(h + 1, str);
            swap(str[h], str[i]);
        }
    }
    vector<string> Permutation(string str) {
        int n = str.size();
        if (n == 0) return res;
        sort(str.begin(), str.end());
        dfs(0, str);
        return res;
    }
};
int main() {
    Solution* a =new Solution();
    a->permutation("aba");
    return 0;
}