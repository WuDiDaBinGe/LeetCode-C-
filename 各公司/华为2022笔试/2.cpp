#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct Node{
    int x, y;
    Node(int xx, int yy):x(xx), y (yy){}
};
int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main() {
    int m, n; cin>>m>>n;
    vector<vector<int>> map(m, vector<int>(n, 1));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int sx, sy, ex, ey;
    cin>>sx>>sy>>ex>>ey;
    int c; cin>>c;
    for(int i = 0; i < c; i++) {
        int x,y; cin>>x>>y;
        map[x][y] = 0;
    }
    // bfs
    queue<Node*> q;
    q.push(new Node(sx, sy));
    int res = 0, level = 0;
    bool flag = false;
    while(!q.empty()) {
        int count = q.size();
        for(int i = 0; i < count; i++) {
            Node* t = q.front(); q.pop();
            visited[t->x][t->y] = true;
            if(t->x == ex && t->y == ey) {
                res++;
                flag = true;
                continue;
            }
            for(int d = 0; d < 4; d++) {
                int nx = t->x + dirs[d][0], ny = t->y +dirs[d][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] || map[nx][ny] == 0) continue;
                // if(nx == ex && ny == ey)
                //     res++; 
                q.push(new Node(nx, ny));
            }
        }
        level++;
        if(flag)
            break;
    }
    cout<<res<<" "<<level - 1<<endl;
    return 0;
}