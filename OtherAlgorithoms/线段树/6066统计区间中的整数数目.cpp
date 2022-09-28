#include<bits/stdc++.h>
using namespace std;
// 使用set求解并区间
class CountIntervals1 {
    typedef pair<int, int> pii;
    // 保存所有无相交的区间
    set<pii> st;
public:
    int res = 0;
    CountIntervals1() {
    }
    void add(int left, int right) {
        int L = left, R = right;
        // 相差1也连接起来
        auto it = st.lower_bound(pii(left - 1, 1e9 + 1));
        while(it != st.end()) {
            // 没有区间相交了
            if(it->second - R > 1) break;
            L = min(L, it->second);
            R = max(R, it->first);
            res -= (it->first - it->second + 1);
            st.erase(it);
        }
        res += (R - L + 1);
        st.insert(pii(R, L));
    }
    int count() {
        return res;
    }
};
// 动态开点线段树
class CountIntervals {
    CountIntervals *left = nullptr, *right = nullptr;
    int l, r, cnt = 0;
public:
    CountIntervals():l(1), r(1e9){}
    CountIntervals(int l, int r):l(l), r(r){}
    void add(int L, int R) {
        if(cnt == r - l + 1) return; // 当前节点已被完整覆盖，无需执行任何操作
        if(L <= l && r <= R) {        // 当前节点已被区间 [L,R] 完整覆盖，不再继续递归
            cnt = r - l + 1;
            return; 
        }
        // 相交的时候
        int mid = (l + r) / 2;
        if(left == nullptr) left = new CountIntervals(l, mid);
        if(right == nullptr) right =new CountIntervals(mid + 1, r);
        if(L <= mid)  left->add(L, R);
        if(R > mid)   right->add(L, R);
        cnt = left->cnt + right->cnt;

    }
    int count() {return cnt;}
};

int main() {
    return 0;
}