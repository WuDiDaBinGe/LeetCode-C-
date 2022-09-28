#include<bits/stdc++.h>
using namespace std;
class BookMyShow {
public:
    vector<int> maxRight;       // 记录每一排 最后一个做了的座位
    int nn, mm;
    int start = 0;
    BookMyShow(int n, int m) {
        maxRight = vector<int>(n, -1);
        nn = n;
        mm = m;
    }
    
    vector<int> gather(int k, int maxRow) {
        if(mm < k) return {};
        int maxn = min(maxRow, nn - 1);
        for(int i = start; i <= maxn; ++i) {
            if((mm - maxRight[i] - 1) >= k) {
                maxRight[i] = maxRight[i] + k;
                //total -= k;
                return {i, maxRight[i] - k + 1};
            }
        }
        return {};
    }
    
    bool scatter(int k, int maxRow) {
        long long sum = 0;
        bool canDo = false;
        int rowIndex = 0;
        int maxn = min(maxRow, nn - 1);
        for(int i = start; i <= maxn; ++i) {
            sum += (mm - maxRight[i] - 1);
            if(sum >= k) {
                canDo = true;
                rowIndex = i;
                int gap = sum - k;
                maxRight[i] = mm - gap -1;
                break;
            }
        }
        if(canDo) {
            for(int i = start; i < rowIndex; ++i) {
                maxRight[i] = mm - 1;
            }
            start = rowIndex;
        }
        return canDo;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */