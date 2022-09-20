#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
    stringstream ss(s);
    string t;
    vector<string> strs;
    while (ss>>t) {
        // 去除多余的空格
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == ' ') continue;
            else {
                t = t.substr(i);
                break;
            }
        }
        strs.push_back(t);
    }
    string res = "";
    for(int i = strs.size() - 1; i >= 0 ; --i) {
        res += strs[i];
        if(i != 0) res += " ";
    }
    return res;
}
// 使用栈的方法
class Solution {
public:
    string ReverseSentence(string str) {
        string res;
        stack<string> stk;
        stringstream ss(str);
        while(getline(ss, res, ' ')) {
            stk.push(res);

        }
        string result = "";
        while(!stk.empty()) {
            result += stk.top();
            stk.pop();
            if(stk.size() >= 1) result += " "; 
        }
        return result;
    }
};

int main() {
    cout<<reverseWords("a good   example");
    return 0;
}