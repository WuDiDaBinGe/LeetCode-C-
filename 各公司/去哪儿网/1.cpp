#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 运动员可得到的最高分
     * @param energy int整型 运动员体力值
     * @param actions int整型vector<vector<>> 二维数组i为动作号 actions[i][0]为动作i+1消耗体力,actions[i][1]为动作i+1得分
     * @return int整型
     */
    int maxScore(int energy, vector<vector<int> >& actions) {
        int n = actions.size();
        vector<int> dp(energy + 1);
        for(int i = 1; i <= n; ++i)
            for(int j = energy; j >= 0; ++j) {
                dp[j] = max(dp[j], dp[j - actions[i - 1][0]] + actions[i - 1][1]);
            }
                
        return dp[energy];
    }
};
int main(){
    int n; cin>>n;
    return 0;
}