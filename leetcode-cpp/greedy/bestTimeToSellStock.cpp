#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    if(prices.size() == 1) return 0;
    int cur_min = prices[0];
    int res = INT8_MIN;
    for(int i = 1; i < prices.size(); i++) {
        res = max(res, prices[i] - cur_min);
        cur_min = min(cur_min, prices[i]);
    }
    return res > 0 ? res : 0;
}
int main() {

    return 0;
}