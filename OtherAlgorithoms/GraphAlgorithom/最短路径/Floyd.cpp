#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAXN 205
using namespace std;
//floyd 算法：多源最短路径
// 注意最大数
const long long inf=2147483647;
int T[MAXN];
int D[MAXN][MAXN];
void floyd(int cur, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            D[i][j] = min(D[i][j], D[i][cur]+D[cur][j]);
            D[j][i] = D[i][j];
        }
    }
}

int main() {
    int N,M;
    cin>>N;cin>>M;
    for(int i = 0; i < N; i++){
        int t;cin>>t;
        T[i] = t;
    }
    // init
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            D[i][j] = 1e9;
    
    for(int i = 0; i < N; i++) 
        D[i][i] = 0;

    for(int i = 0; i < M; i++) {
        int f,e,d;
        cin>>f;cin>>e;cin>>d;
        D[f][e] = d;
        D[e][f] = d;
    }
    // floyd algorithm
    int q; cin>>q;
    int cur = 0;        // 表示更新到的村庄序号
    for(int i = 0; i < q; i++) {
        int f,e,t;
        cin>>f;cin>>e;cin>>t;
        while (cur < N && T[cur] <= t) {
            floyd(cur, N);
            cur++;
        }
        if(T[f] > t|| T[e] > t) cout<<-1<<endl;
        else{
            if(D[f][e] == 1e9) cout<<-1<<endl;
            else cout<<D[f][e]<<endl;
        }
    }
    return 0;
}