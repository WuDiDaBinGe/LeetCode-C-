#include<bits/stdc++.h>
using namespace std;
vector<int> sums(101);
vector<long long> prefix(101);
long long f(int n) {
    long long sum = 0;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            sum += i;
            if(i != n / i)
                sum += n / i;
        }
    }
    return sum;
}
int main()
{
   for(int i = 1; i < 101; ++i) {
        sums[i] = f(i);
        prefix[i] += prefix[i - 1] + sums[i];
   }
   int t;cin>>t;
   for(int i = 0; i < t; ++i) {
        long long m; cin>>m;
        auto pos = lower_bound(prefix.begin(), prefix.end(), m);
        if(pos == prefix.end() || *pos != m) 
            cout<<-1<<endl;
        else
            cout<<(pos - prefix.begin())<<endl;
   }
   return 0;
}