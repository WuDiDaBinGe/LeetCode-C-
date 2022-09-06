#include<bits/stdc++.h>
using namespace std;

int main()
{
    int S; cin>>S;
    long long base = 1,  res = 0;
    long long sum_zhishu = 0;
    for(long long i = 1; ; i = i << 1) {
        if(S > sum_zhishu + i) {
            res += base * i;
            sum_zhishu += i;
        } else {
            res += base * (S - sum_zhishu);
            break;
        }
        base++;
    }
    cout<<res<<endl;
    return 0;
}