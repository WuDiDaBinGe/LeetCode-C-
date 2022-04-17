#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAXN 100009
#define MAXM 200009
using namespace std;
// 注意最大数
const long long inf=2147483647;
// dijstra算法
// 寻找单源最少路径 即一个点 到 所有点的最短路径
struct Edge {
    int from, to, dist;
    Edge(int f, int t, int d):from(f), to(t), dist(d){}
};
struct HeapNode {
    /* data */
    int index, dist;
    HeapNode(int i, int d):index(i), dist(d){}
    bool operator < (const HeapNode& b) const{
        return dist > b.dist;
    }
};

struct Dijkstra
{
    int n, m;               //节点个数、边的个数
    vector<Edge> edges;     //边的集合
    vector<int> G[MAXN];    //邻接表
    int d[MAXN];            //记录最短路径
    int p[MAXN];            //记录父节点
    bool visited[MAXN];     //标记——记录是否在集合S中
    void init(int n) {
        this->n = n;
        for(int i = 1; i <= n; i++)
            G[i].clear();
        edges.clear();
    }
    void addEdge(int from, int end, int distance) {
        edges.push_back(Edge(from, end, distance));
        m = edges.size();
        //添加边的序号
        G[from].push_back(m - 1);
    }
    void dijkstra(int s) {
        priority_queue<HeapNode> Q;
        Q.push(HeapNode(s, 0));
        for(int i = 1; i <= n; i++) d[i] = inf; 
        d[s] = 0;
        memset(visited, 0, sizeof(visited));
        while (!Q.empty()) {
            HeapNode head = Q.top(); Q.pop();
            int node_index = head.index;
            // 已经在扩展集合中了 下一个
            if (visited[node_index]) continue;
            // 加入扩展集合
            visited[node_index] = true;
            // 更新最短距离
            for(int i = 0; i < G[node_index].size(); i++) {
                // 该点的每一条边
                Edge e = edges[G[node_index][i]];
                if(d[e.to] > d[e.from] + e.dist) {
                    d[e.to] = d[e.from] + e.dist;
                    p[e.to] = G[node_index][i];
                    Q.push(HeapNode(e.to, d[e.to]));
                }
            }
        }
        
    }
};

int main() {
    int n,m,s;
    cin>>n;cin>>m;cin>>s;
    Dijkstra dij;
    dij.init(n);
    for(int i = 0; i < m; i++) {
        int f,t,d;
        cin>>f;cin>>t;cin>>d;
        dij.addEdge(f, t, d);
    }
    dij.dijkstra(s);
    for(int i = 1; i <=n; i++) {
        cout<<dij.d[i]<<" ";
    }
    return 0;
}