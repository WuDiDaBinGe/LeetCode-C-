#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
vector<int> path;
void dfs(int index, vector<int>& prices, int sum, int target) {
    if(sum == target) {
        result.push_back(path);
        return ;
    }
    for(int i = index; i < prices.size(); i++) {
        // purn
        if(sum + prices[i] > target) break;
        path.push_back(prices[i]);
        dfs(i + 1, prices, sum + prices[i], target);
        path.pop_back();
        while (i + 1 < prices.size() && prices[i + 1] == prices[i])
        {
            i++;
        }
        
    }
}
int main(){
    vector<int> prices={1,2,3,4,5};
    int target = 5;
    dfs(0, prices, 0, target);
    cout<<result.size()<<endl;
    return 0;
}