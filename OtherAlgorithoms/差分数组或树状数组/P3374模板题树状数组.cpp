#include<bits/stdc++.h>
using namespace std;
struct BIL {
    vector<int> tree;
    BIL(int n) {
        tree = vector<int>(n + 1, 0);
    }
    int lowbits(int x) {
        return x & (-x);
    }
    void add(int index, int k) {
        while(index < tree.size()) {
            tree[index] += k;
            index += lowbits(index);
        }
    }
    // 返回[0, index]的前缀和
    int ask(int index) {
        int res = 0;
        while(index > 0) {
            res += tree[index];
            index -= lowbits(index);
        }
        return res;
    }
};
int main() {
    int n, m;
    cin>>n>>m;
    BIL* bil = new BIL(n);
    for(int i = 1; i <= n; i++) {
        int t; cin>>t;
        bil->add(i, t);
    }
    for(int i = 0; i < m; i++) {
        int type, a, b; cin>>type>>a>>b;
        if(type == 1) {
            bil->add(a, b);
        } else if(type == 2) {
            int all = bil->ask(b);
            int prefix = bil->ask(a - 1);
            cout<<all - prefix<<endl;
        }
    }  
    
    return 0;
}