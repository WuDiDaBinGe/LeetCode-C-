
#include<bits/stdc++.h>
using namespace std;
bool check(string &s) {
    int n = s.size();
    if(n < 6) return false;
    int num = 0;
    int alpha = 0;
    int m_alpha = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] >= '0' && s[i] <= '9') {
            num++; m_alpha = 0;
        } else {
            alpha++;
            m_alpha++;   
            if(m_alpha >= 5) return false;
        }
        if(i > 0 && s[i - 1] == s[i])
            return false;
    }
    if(num >= alpha) return false;
    return true;
}
int main()
{
   int n; cin>>n;
   for(int i = 0; i < n; ++i) {
        string s; cin>>s;
        if(check(s))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
   }
   return 0;
}