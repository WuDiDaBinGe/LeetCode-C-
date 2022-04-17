#include<iostream>
#include<vector>
using namespace std;
//遇到高的就卖出
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n == 1) return 0;
    int profix = 0;
    int curMin = prices[0];
    for(int i = 1; i < n; i++) {
        if(prices[i] > curMin) {
            profix += prices[i] - curMin;
            curMin = prices[i];
        }
        else {
            curMin = prices[i];
        }
    }
    return profix;
}
int main() {
    vector<int> prices = {7,6,4,3,1};
    cout<<maxProfit(prices)<<endl;
    return 0;
}