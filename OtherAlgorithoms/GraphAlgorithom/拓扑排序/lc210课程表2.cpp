#include<bits/stdc++.h>
using namespace std;
// 使用bfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        vector<int> inDrgree(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i) {
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDrgree[prerequisites[i][0]]++;
        }
        //topo
        queue<int> q;
        vector<int> path;
        for(int i = 0; i < numCourses; ++i)
            if(inDrgree[i] == 0) q.push(i);
        while(!q.empty()) {
            int out = q.front(); q.pop();
            path.push_back(out);
            for(int i = 0; i < G[out].size(); ++i) {
                inDrgree[G[out][i]]--;
                if(inDrgree[G[out][i]] == 0) q.push(G[out][i]);
            }
        }
        return path.size() == numCourses ? path : vector<int>();
    }
};
// 使用bfs
class Solution {
public:
    vector<vector<int>> G;
    vector<int> result;
    // 0 表示未开始搜索 1表示搜索中 2表示搜索完毕
    vector<int> visited;
    bool cycle = false;
    void dfs(int index) {
        // 开始搜索
        visited[index] = 1;
        for(int i = 0; i < G[index].size(); ++i) {
            int next = G[index][i];
            if(visited[next] == 1) {
                cycle = true;
                return;
            } 
            else if(visited[next] == 0) {
                dfs(next);
            }
        }
        // 搜索完成
        visited[index] = 2;
        result.push_back(index);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        G.resize(numCourses);
        visited.resize(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i) {
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //topo
        for(int i = 0; i < numCourses; ++i) {
            if(visited[i] == 0) dfs(i);
        }
        reverse(result.begin(), result.end());
        return cycle ? vector<int>() : result;
    }
};