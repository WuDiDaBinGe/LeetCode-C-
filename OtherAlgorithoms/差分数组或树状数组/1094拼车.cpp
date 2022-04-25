#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int a[1010], d[1010];
    // 典型差分数组题
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        int maxD = INT_MIN;
        for(int i = 0; i < n; i++) {
            auto vec = trips[i];
            d[vec[1]] += vec[0];
            d[vec[2]] -= vec[0];
            maxD = max(maxD, vec[2]); 
        }
        a[0] = d[0];
        if(a[0] > capacity) return false;
        for(int i = 1; i <= maxD; i++) {  
            a[i] = a[i - 1] + d[i];
            if(a[i] > capacity) return false;
        }
        return true;
    }
};