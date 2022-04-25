#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
vector<int> path;
vector<bool> visited;
void dfs(int index, int count, int k, int n) {
    if(count == k) {
        for(int i = 0; i < path.size(); i++) {
            cout<<path[i]<<" ";
        }
        cout<<endl;
        res.push_back(path);
    }
    // get chioce
    // 组合
    for(int i = index; i <= n; i++) {
        if(visited[i]) continue;
        path.push_back(i);
        visited[i] = true;
        dfs(i + 1, count + 1, k, n);
        path.pop_back();
        visited[i] = false;
    }
}
vector<vector<int>> combine(int n, int k) {
    visited = vector<bool>(n + 1, false);
    dfs(1, 0 , k, n);
    return res;
}

int main() {
    combine(4, 2);
    return 0;
}