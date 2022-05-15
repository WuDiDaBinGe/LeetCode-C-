#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;
ll n, m;
ll nums[MAXN];
ll tree[MAXN << 2];
ll mark[MAXN << 2];
// 构建线段树
void build(ll left, ll right, ll p) {
    // 叶子节点
    if(left == right) {
        tree[p] = nums[left];
    }
    else {
        ll mid = (left + right)>>1;
        build(left, mid, p << 1);
        build(mid + 1, right, p << 1 | 1);
        tree[p] = tree[p << 1] + tree[p << 1 | 1]; 
    }
}
//lazy标记下移操作
void push_down(ll p, ll l, ll r) {
    // p 为父节点
    ll mid = (l + r) >> 1;
    mark[p << 1] += mark[p];
    mark[p << 1 | 1] += mark[p];
    tree[p << 1] += (mid - l + 1) * mark[p];
    tree[p << 1 | 1] += (r - mid) * mark[p]; 
    // 清除lazy标记
    mark[p] = 0;
}
// 区间修改
void update(ll t_left, ll t_right, ll d, ll p = 1, ll cleft = 1, ll cright = n) {
    //不相交
    if(cleft > t_right | cright < t_left)
        return;
    // 目标区间包含区间
    else if(t_left <= cleft && t_right >= cright) {
        tree[p] += (cright - cleft + 1) * d;
        if(cright > cleft)
            mark[p] += d;
    }
    // 区间相交
    else {
        ll mid = (cleft + cright) >> 1;
        push_down(p, cleft, cright);
        update(t_left, t_right, d, p << 1, cleft, mid);
        update(t_left, t_right, d, p << 1 | 1, mid + 1, cright); 
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }
}
// 区间查询
ll query(ll t_left, ll t_right, ll p = 1, ll cleft = 1, ll cright = n) {
    if(cleft > t_right | cright < t_left)
        return 0;
    else if(t_left <= cleft && t_right >= cright) {
        return tree[p];
    }
    else {
        ll mid = (cleft + cright) >> 1;
        push_down(p, cleft, cright);
        return query(t_left, t_right, p << 1, cleft, mid) 
            +  query(t_left, t_right, p << 1 | 1, mid + 1, cright);
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1; i <= n; ++i) {
        cin>>nums[i];
    }
    build(1, n, 1);
    for(int k = 0; k < m; ++k) {
        int type; cin>>type;
        int s, e, d;
        // 区间修改
        if(type == 1) {
            cin>>s>>e>>d;
            update(s, e, d);
        }
        // 区间查询
        else if(type == 2) {
            cin>>s>>e;
            // 注意数据范围
            ll res = query(s, e);
            cout<<res<<endl;
        }
    }
    return 0;
}