#include<bits/stdc++.h>
using namespace std;
// 使用set求解并区间
class CountIntervals {
    typedef pair<int, int> pii;
    // 保存所有无相交的区间
    set<pii> st;
public:
    int res = 0;
    CountIntervals() {

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
int main() {
    return 0;
}