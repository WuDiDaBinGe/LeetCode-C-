// #include<bits/stdc++.h>
// using namespace std;
// #define MOD 1000000007;
// // 快速幂取余
// long long QuickyMI(long long base, int n) {
//     long long res = 1;
//     while (n > 0) {
//         if(n & 1) res = (res * base)  % MOD;
//         base = (base * base) % MOD;
//         n = n / 2;  // n = n >> 1;
//     }
//     return res;
// }
// int main()
// {
//    int n;cin>>n;
//    long long res = 0;
//    if(n < 6) {
//         cout<<0<<endl;
//         return 0;
//    }
//    if(n == 6) {
//         cout<<1<<endl;
//         return 0;
//    }
//    long long dp = 1;
//    long long num = n / 3;
//    for(int i = n; i >=2; --i) {
//         dp = dp + (num * (QuickyMI(26, 3) - 1) );
//         dp = dp % MOD;
//         num--;
//    }
//    cout<<dp; 
//    return 0;
// }

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
ll dp[N][4];
void init(int n){
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++){
		dp[i][0] = (dp[i - 1][0] * 25 % mod + dp[i - 1][1] * 24 % mod + dp[i - 1][2] * 24 % mod) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][2] = dp[i - 1][1];
	}
}
int main()
{
	int n;
	cin >> n;
	ll ans = 1;
	for(int i = 1; i <= n; i ++){
		ans = ans * 26 % mod;
	}
	init(n);
	ans = (ans - (dp[n][0] + dp[n][1] + dp[n][2]) % mod + mod) % mod;
	for(int i = 1; i <= n - 2; i ++){
		ll left = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
		ll right = (dp[n - i - 2][0] + dp[n - i - 2][1] + dp[n - i - 2][2]) % mod;
		ans = (ans - left * right % mod + mod) % mod;
	}
	cout << ans << endl;
	return 0;
}