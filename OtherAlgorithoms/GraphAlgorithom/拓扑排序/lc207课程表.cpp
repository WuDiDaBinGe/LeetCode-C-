#include<bits/stdc++.h>
using namespace std;
#define MAXNUM 100010
class Solution {
public:
    vector<int> G[MAXNUM];
    int indegree[MAXNUM];
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(n == 0) return true;
        // init
        for(int i = 0; i < n; ++i) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            G[v].push_back(u);
            indegree[u]++;
        }
        // topo
        queue<int> q;
        int vCount = 0;
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int index = q.front(); q.pop();
            vCount++;
            for(int i = 0; i < G[index].size(); ++i) {
                int v = G[index][i];
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        // 存在环
        if(vCount != numCourses) return false;
        return true;
    }
};