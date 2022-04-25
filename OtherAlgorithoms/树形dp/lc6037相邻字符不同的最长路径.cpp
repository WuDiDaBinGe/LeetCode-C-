#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
class Solution {
public:
    vector<int> G[N];
    int d[N], f[N];
    int result = 1;
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        if(n == 1) return 1;
        for(int i = 1; i < n; i++) {
            G[parent[i]].push_back(i);
        }
        dfs(0, s);
        return result;
    }
    void dfs(int index, string& s) {
        d[index] = 1;
        f[index] = 1;
        for(int i = 0; i < G[index].size(); i++) {
            int v = G[index][i];
            char c = s[v];
            dfs(v, s);
            if(c != s[index]) {
                result = max(result, d[index] + d[v]); 
                d[index] = max(d[index], d[v] + 1);
            }
        }
    }
};
int main() {
    return 0;
}