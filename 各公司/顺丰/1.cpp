#include<bits/stdc++.h>
using namespace std;
string lltostring(long long t) {
    string result;
    stringstream ss;
    ss << t;
    ss>>result;
    return result;
}
int check(long long s) {
    string l = lltostring(s);
    int n = 0;
    for(int i = 0; i < l.size(); ++i) {
        if(l[i] == '5') n++;
        if(n >= 5) break;
    }
    return n;
}

int main()
{
    long long s;cin>>s;
    for(s = s + 1; ;s++) {
        if(check(s) >= 5) {
            cout<<s<<endl;
            return 0;
        } 
    }
    return 0;
}
