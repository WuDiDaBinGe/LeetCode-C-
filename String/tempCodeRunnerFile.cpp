#include<bits/stdc++.h>
using namespace std;
#define MAXNUM  20000010
// C++ Version
//https://oi-wiki.org/string/z-func/
int extds[MAXNUM];
int zfuns[MAXNUM];
string a,b;
int n, m;
//理解版
inline void z_functionmy() {
    // [l , r]记录目前r最大的区间
    zfuns[0] = m;
    for(int i = 1, l = 0, r = 0; i < m; i++) {
        if(i <= r) {
            if(zfuns[i - l] < r - i + 1) 
                zfuns[i] = zfuns[i - l];
            else {
                zfuns[i] = r - i + 1;
                while(i + zfuns[i] < m && b[zfuns[i]] == b[i + zfuns[i]]){
                } 
            }
        } else {
            while(i + zfuns[i] < m && b[zfuns[i]] == b[i + zfuns[i]]){
                zfuns[i]++;
            } 
        }   
        if(i + zfuns[i] - 1 > r) l = i, r = i + zfuns[i] - 1;
    }
}

//a为任意字符串 p为模式串
void expkmp() {
    string p = b;
    z_functionmy();
    // [l , r]记录目前r最大的区间
    // i 表示每个后缀的开始位置
    for(int i = 0, l = 0, r = 0; i < n; i++) {
        if(i <= r && zfuns[i - l] < r - i + 1) {
            extds[i] = zfuns[i - l]; 
        } else {
            extds[i] = max(0, r - i + 1);
            while(i + extds[i] < n && extds[i] < m && a[i + extds[i]] == p[extds[i]]) extds[i]++;
        }   
        if(i + extds[i] - 1 > r) l = i, r = i + extds[i] - 1;
    }
    return ;
}
int main() {
    cin>>a>>b;
    n = a.size();
    m = b.size();
    expkmp();
    long long  sum = 0;
    for(int i = 1; i <= m; i++){
        sum ^= 1LL * i * (zfuns[i - 1] +1) ;
        //cout<<zfuns[i]<<" ";
    }
    //cout<<endl;
    printf("%lld\n", sum);
    sum = 0;
    for(int i = 1; i <= n; i++) {
        sum ^= 1LL * i * (extds[i - 1] + 1);
    }
    //cout<<endl;
    printf("%lld\n", sum);
    return 0;
}