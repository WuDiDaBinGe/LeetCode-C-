#include<bits/stdc++.h>
using namespace std;
// C++ Version
//https://oi-wiki.org/string/z-func/
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
vector<int> z_functionmy(string s) {
    int n = s.size();
    vector<int> zfuns(n, 0);
    // [l , r]记录目前r最大的区间
    for(int i = 1, l = 0, r = 0; i < n; i++) {
        if(i <= r) {
            if(zfuns[i - l] <= r - i + 1) 
                zfuns[i] = zfuns[i - l];
            else {
                zfuns[i - 1] = r - i + 1;
                while(i + zfuns[i] < n && s[zfuns[i]] == s[i + zfuns[i]]) zfuns[i]++;
            }
        } else {
            while(i + zfuns[i] < n && s[zfuns[i]] == s[i + zfuns[i]]) zfuns[i]++;
        }   
        if(i + zfuns[i] - 1 > r) l = i, r = i + zfuns[i] - 1;
    }
    zfuns[0] = n;
    return zfuns;
}

//a为任意字符串 p为模式串
vector<int> expkmp(string a, string p) {
    int n = a.size();
    int m = p.size();
    vector<int> zfuns = z_functionmy(p);
    vector<int> extds(n, 0);
    // [l , r]记录目前r最大的区间
    for(int i = 0, l = 0, r = 0; i < n; i++) {
        if(i <= r) {
            if(zfuns[i - l] <= r - l + 1) {
                extds[i] = zfuns[i - l];
            } else{
                extds[i] = r - i + 1;
                while(i + extds[i] < n && extds[i] < m && a[i + extds[i]] == p[extds[i]]) extds[i]++;
            }
        } else {
            while(i + extds[i] < n && extds[i] < m && a[i + extds[i]] == p[extds[i]]) extds[i]++;
        }   
        if(i + zfuns[i] - 1 > r) l = i, r = i + zfuns[i] - 1;
    }
    return extds;
}
int main() {
    string a,b;
    cin>>a>>b;
    vector<int> z = z_functionmy(b);
    int sum = 0;
    for(int i = 0; i < z.size(); i++){
        sum += z[i];
        cout<<z[i]<<" ";
    }
    cout<<endl;
    cout<<sum<<endl;
    sum = 0;
    vector<int> p = expkmp(a, b);
    for(int i = 0; i < p.size(); i++) {
        sum += p[i];
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}