#include<iostream>
#include<vector>
using namespace std;
/*
    动态规划：初始dp[0]=0;dp[1]=1;
    在第n个台阶的走法：dp[n]=dp[n-1]+dp[n-2]
*/
int climbStairs(int n) {
    if (n==1)
        return 1;
    if (n==2)
        return 2;
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) 
        dp[i] = dp[i-2] + dp[i-1];
    return dp[n];
}
int main(){
    cout<<climbStairs(3)<<endl;
    return 0;
}