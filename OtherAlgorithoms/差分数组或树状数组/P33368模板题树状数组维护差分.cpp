#include<bits/stdc++.h>
using namespace std;
#define MAXN 500010
int N, M;
struct BIL {
    // 差分数组
    vector<int> tree;
    // 数组元素
    vector<int> num;
    int lowbits(int x) {
        return x & (-x);
    }
    BIL(int n) {
        tree = vector<int>(n + 1);
        num = vector<int>(n + 1);
    }
    int ask(int index) {
        int res = 0;
        while(index >= 1) {
            res += tree[index];
            index -= lowbits(index);
        }
        return res;
    }
    void update(int index, int num) {
        while (index <= N) {
            tree[index] += num;
            index += lowbits(index);
        }
    }
};
int main() {
    cin>>N>>M;
    BIL* bil = new BIL(N);
    for(int i = 1; i <= N; i++) 
        cin>>bil->num[i];
    for(int m = 0; m < M; m++) {
        int type; cin>>type;
        if(type == 1) {
            int x, y, num;
            cin>>x>>y>>num;
            bil->update(x, num);
            bil->update(y + 1, -1 * num);
        }
        else if(type == 2) {
            int index; cin>>index;
            cout<<bil->num[index] + bil->ask(index)<<endl;
        }
    }
    return 0;
}