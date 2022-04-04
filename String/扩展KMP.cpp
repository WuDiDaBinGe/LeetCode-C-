#include<bits/stdc++.h>
using namespace std;
#define MAXNUM  20000010
// C++ Version
//https://oi-wiki.org/string/z-func/
// 效率提升
// 1. ++i 
int extds[MAXNUM];
int zfuns[MAXNUM];
char a[MAXNUM],b[MAXNUM];
int n, m;
vector<int> z_function_baoli(string s) {
    int n = s.size();
    vector<int> zfuns(n, 0);
    for(int i = 1; i < n; i++) {
        while(i + zfuns[i] < n && s[zfuns[i]] == s[i + zfuns[i]]) zfuns[i]++;
        cout<<zfuns[i]<<" ";
    }
    cout<<endl;
    return zfuns;
}
// 简化版
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
//理解版
void z_functionmy() {
    // [l , r]记录目前r最大的区间
    zfuns[0] = m;
    for(int i = 1, l = 0, r = 0; i < m; ++i) {
        if(i <= r) {
            if(zfuns[i - l] < r - i + 1) 
                zfuns[i] = zfuns[i - l];
            else {
                zfuns[i] = r - i + 1;
                while(i + zfuns[i] < m && b[zfuns[i]] == b[i + zfuns[i]]){
                    zfuns[i]++;
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
    z_functionmy();
    // [l , r]记录目前r最大的区间
    // i 表示每个后缀的开始位置
    int now = 0;
    while(now < n && now < m && b[now] == a[now]) now++;
    extds[0] = now; 
    for(int i = 1, l = 0, r = 0; i < n; ++i) {
        if(i <= r ){
            if(zfuns[i - l] < r - i + 1) {
                extds[i] = zfuns[i - l]; 
            } else {
                extds[i] = r - i + 1;
                while(i + extds[i] < n && extds[i] < m && a[i + extds[i]] == b[extds[i]]) extds[i]++;
            }
        } else {
            while(i + extds[i] < n && extds[i] < m && a[i + extds[i]] == b[extds[i]]) extds[i]++;
        }   
        if(i + extds[i] - 1 > r) l = i, r = i + extds[i] - 1;
    }
}
int main() {
    scanf("%s%s",a,b);
    n = strlen(a);
    m = strlen(b);
    expkmp();
    long long sum = 0, sum2 = 0;
    for(int i = 0; i < m; ++i){
        sum ^= (long long) (i +1) * (zfuns[i] +1) ;
    }
    sum2 = 0;
    for(int i = 0; i < n; ++i) {
        sum2 ^= (long long)  (i + 1) * (extds[i] + 1);
    }
    printf("%lld\n%lld\n", sum, sum2);
    return 0;
}