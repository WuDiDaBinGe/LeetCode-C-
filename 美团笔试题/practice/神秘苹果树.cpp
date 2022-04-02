#include <bits/stdc++.h>
using namespace std;
vector<int> G[5010];
int Color[5010];
void modify(int root) {
    if(G[root].size()) {
        for(int i = 0 ; i < G[root].size(); i++) {
            int r = G[root][i];
            auto iter = remove(G[r].begin(), G[r].end(), root);
            G[r].erase(iter, G[r].end());
            modify(r);
        }
    }
}
int main() {
    int n; cin>>n;
    
    for(int i = 1; i <= n - 1; i++) {
        int s,e;cin>>s>>e;
        G[s].push_back(e);
        G[e].push_back(s);
    }
    for(int i = 1; i <= n; i++)
        cin>>Color[i];
    int Q;cin>>Q;
    for(int q = 0; q < Q; q++) {
        int root; cin>>root;
    }
    return 0;
}