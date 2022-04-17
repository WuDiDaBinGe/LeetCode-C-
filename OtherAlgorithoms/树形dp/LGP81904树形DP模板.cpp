#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+100;
struct Edage {
    int u, v;
    int weight;
    int next;
};
Edage e[2 * N];
int head[N], cnt = 0;
bool visited[N];
void insert(int u, int v, int weight) {
    cnt++;
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt].weight = weight;
    e[cnt].next = head[u];
    head[u] = cnt;
}
//f表示以x为根的路径长度 d表示x为根的到子孙的最长距离
int f[N], d[N];
void dfs(int u) {
    visited[u] = true;
    int e_index = head[u];
    while(e_index != -1) {
        int v = e[e_index].v;
        int w = e[e_index].weight;
        if(!visited[v]) {
            dfs(v);
            f[u] = max(max(f[u], d[u]), max(d[v] + w, d[u] + d[v] + w));
            d[u] = max(max(d[u], w), d[v] + w);
        }
        e_index = e[e_index].next;
    }
}
int main() {
    memset(head, -1, sizeof(head));
    memset(visited, false, sizeof(visited));
    int n; cin>>n;
    for(int i = 1; i < n; i++){
        int u,v,w;cin>>u>>v>>w;
        insert(u, v, w);
        insert(v, u, w);
    }
    dfs(1);
    int res = INT_MIN;
    for(int i = 1; i <= n; i++) res = max(res, f[i]);
    cout<<res<<endl;
    return 0;
}