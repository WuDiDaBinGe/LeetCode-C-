#include<iostream>
#include<vector>
#define MAXNUM 5003
using namespace std;
int P[MAXNUM];
int Rank[MAXNUM];
//初始化并查集
void init(int n) {
    // 每个元素相互独立
    for(int i = 1; i <= n; i++) {
        P[i] = i;
        Rank[i] = 1;
    }
}
// 查找操作
int find(int i) {
    return P[i] == i ? i : P[i] = find(P[i]);
}
// 合并操作
void merge(int i, int j) {
    int x  = find(i), y = find(j);
    if(x == y) return;
    // 深度小的树 先 深度深的树合并
    if(Rank[x] <= Rank[y]) {    
        P[x] = y;
    }
    else{
        P[y] = x;
    }
    //如果深度相同且根节点不同，则新的根节点的深度+1
    if(Rank[x] == Rank[y] && x != y) 
        Rank[y]++;
    
}
int main() {
    int n, m, p;
    cin>>n;cin>>m;cin>>p;
    int s, t;
    //初始化
    init(n);
    for(int i = 0; i < m; i++) {
        cin>>s; cin>>t;
        merge(s, t);
    }
    for(int i = 0; i < p; i++) {
        cin>>s; cin>>t;
        if(find(s) == find(t)) 
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}