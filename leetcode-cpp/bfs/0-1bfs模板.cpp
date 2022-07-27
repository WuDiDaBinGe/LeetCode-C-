#include<bits/stdc++.h>
using namespace std;
class Solution {
    int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();                 //变量及容器定义
        vector<vector<int>>dist(n,vector<int>(m,1e9));      //把初始距离定义的大一点（因为要求最小值）。
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        deque<pair<int,int>>de;

        de.push_front({0,0});                               //初始化
        dist[0][0]=0;
        while(de.size()){
            auto [x,y]=de.front();                           //取deque头部元素
            de.pop_front();
            if(vis[x][y])continue;                          //如果访问过则跳过
            vis[x][y]=true;

            for(auto& [dx,dy]:dirs){                         //四个方向
                int next_x=x+dx;
                int next_y=y+dy; 

                if(next_x>=0 && next_x<n && next_y>=0 && next_y<m){
                    int dis=dist[x][y]+grid[next_x][next_y];                                                //根据题意求取距离
                    if(dist[next_x][next_y]>dis)dist[next_x][next_y]=dis;                                   //满足条件更新距离
                    grid[next_x][next_y]==0?de.push_front({next_x,next_y}):de.push_back({next_x,next_y});   //0放入头部，1放入尾部。

                }

            }
        }
        return dist[n-1][m-1];   //返回结果。
    }
};
class Solution1 {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}};
    // 使用广度优先搜索
    int movingCount(int m, int n, int k) {
        if(k == 0) return 1;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        q.emplace(0, 0);
        while(!q.empty()) {
            auto poi = q.front(); q.pop();
            int x = poi.first, y = poi.second;
            if(visited[x][y]) continue;
            visited[x][y] = true;
            ans++;
            for(int i = 0; i < 2; ++i) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >=n || check(nx, ny) > k) continue;
                q.emplace(nx, ny);
            }
        } 
        return ans;
    }
    int check(int x, int y) {
        int res = 0;
        while(x) {
            res += x % 10;
            x /= 10;
        }
        while(y) {
            res += y % 10;
            y /= 10;
        }
        return res;
    }
    
};