#include<iostream>
#include<vector>
#include<algorithm>
#define MAXNUM 200005
using namespace std;
// Kruskal算法
int W[MAXNUM], S[MAXNUM], T[MAXNUM], R[MAXNUM];
int P[5005];
void init(int n) {
    for(int i = 1; i <= n; i++) {
        P[i] = i;
    }
}
int find(int i) {
    return P[i] == i ? i : P[i] = find(P[i]);
}
bool cmp(int i, int j) {
    return W[i] < W[j];
}
int main() {
    int N, M, res = 0;
    cin>>N;cin>>M;
    init(N);
    for(int i = 0; i < M; i++) {
        int s, t, w;
        cin>>s;cin>>t;cin>>w;
        S[i] = s; T[i] = t; W[i] = w;
        R[i] = i;
    }
    //按照边的权重排序
    sort(R, R + M, cmp);
    for(int i = 0; i < M; i++) {
        int w = W[R[i]], s = S[R[i]], t = T[R[i]];
        int x = find(s), y = find(t);
        // 两者在一个连通图 这样的边不满足
        if(x == y) continue;
        // 结果相加
        res += w;
        // 合并
        P[x] = y;
    }
    cout<<res<<endl;
    return 0;
}