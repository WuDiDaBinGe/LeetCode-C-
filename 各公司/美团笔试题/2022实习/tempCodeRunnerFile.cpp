#include<bits/stdc++.h>
using namespace std;
bool isSubSeq(string a, string b) {
    int p1 = 0, p2 = 0;
    while (p2 < b.size()) {
        if(a[p1] == b[p2]) {
            p1++;
            p2++;
            if(p2 != b.size() && p1 == a.size())
                return false;
        } else {
            p1++;
            if(p1 == a.size())
                return false;
        }
    }
    return true;
}
int main() {
    string a,b;
    cin>>a>>b;
    int res = 0;
    for(int i = 0; i < a.size() - b.size(); i++) {
        for(int j = i + b.size(); j <= a.size(); j++) {
            string s = a.substr(i, j - i);
            if(isSubSeq(s, b)) {
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}