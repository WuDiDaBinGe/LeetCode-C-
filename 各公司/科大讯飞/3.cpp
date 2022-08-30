#include<bits/stdc++.h>
using namespace std;
#define MAXNUM 100010
/*
    拓扑排序 + dp
*/
map<int, vector<int>> G;
map<int, int> indegree;
int main()
{
   int numCourses; cin>>numCourses;
   int maxIndex = 0;
   map<int, int> dp;
   for(int i = 0; i < numCourses; ++i) {
        int s,e; string con;
        cin>>s>>e>>con;
        maxIndex = max(maxIndex, s);
        maxIndex = max(maxIndex, e);
        if(G.find(e) == G.end()) {
            vector<int> tmp;
            G[e] = tmp; dp[e] = 0;indegree[e] = 0;
        }
        if(G.find(s) == G.end()) {
            vector<int> tmp;
            G[s] = tmp; indegree[s] = 0; dp[s] = 0;
        }
        if(con == "true") {
            G[e].push_back(s);
            indegree[s]++;
        }
   }
   // topo
   queue<int> q;

   for(auto item:indegree) {
        if(item.second == 0) q.push(item.first);
   }
   while(!q.empty()) {
        int index = q.front(); q.pop();
        for(int i = 0; i < G[index].size(); ++i) {
            int v = G[index][i];
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
            dp[v] = max(dp[v], dp[index] + 1);
        }
   }
   for(auto item:dp) {
        cout<<item.first<<" "<<item.second<<endl;
   }
   return 0;
}