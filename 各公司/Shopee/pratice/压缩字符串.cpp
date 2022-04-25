#include<bits/stdc++.h>
using namespace std;
string compressString(string param) {
    int n = param.size();
    if(n <= 1) return param;
    param.push_back('#');
    n = n + 1;
    string res = "";
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(param[i] != param[i - 1]) {
            res += param[i - 1];
            if(count > 1)
                res += to_string(count);
            count = 1;
        } else{
            count++;
        }
    }
    return res;
}
int main() {
    cout<<compressString("A")<<endl;
    cout<<compressString("weeAAaac")<<endl;
    cout<<compressString("aaaaaa")<<endl;
    cout<<compressString("AAaSSs")<<endl;
    return 0;
}