#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    char c; cin>>c;
    c = tolower(c);
    int res = 0;
    for(int i = 0; i < s.size(); i++) {
        if(tolower(s[i]) == c)
            res++;
    }
    cout<<res<<endl;
    return 0;
}