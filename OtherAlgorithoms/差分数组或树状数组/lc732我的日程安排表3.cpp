#include<bits/stdc++.h>
using namespace std;
class MyCalendarThree {
public:
    map<int, int> diff;
    int res = INT_MIN;
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        diff[start]++;
        diff[end]--;
        int cur = 0;
        for(auto& kv:diff) {
            cur += kv.second;
            res = max(res, cur);
        }
        return res;
    }
};