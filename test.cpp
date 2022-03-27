#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int T1[2002], T2[2002];
void printRes(int totalm){
    int minute = totalm / 60;
    int hour = totalm / 3600;
    int second = totalm % 60;
    //am
    if(hour <= 4) {
        printf("%02d:%02d:%02d am\n",8+hour, minute, second);
    } else{
        printf("%02d:%02d:%02d pm\n",(8+hour) % 12, minute, second);
    }
}
int main() {
    int count;cin>>count;
    for(int i = 0; i < count; i++) {
        int n;cin>>n;
        for(int j = 0; j < n; j++)
            cin>>T1[j];
        for(int j = 1; j <= n - 1; j++)
            cin>>T2[j];
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = T1[0];
        for(int j = 2; j <= n; j++) {
            dp[j] = min(dp[j - 1] + T1[j -1], dp[j - 2] + T2[j - 1]);
            cout<<dp[j]<<endl;
        }
        printRes(dp[n]);
    }
    return 0;
}