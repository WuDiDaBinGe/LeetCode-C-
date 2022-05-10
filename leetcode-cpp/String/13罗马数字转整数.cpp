#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<char, int> mp = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int romanToInt(string s) {
        int n = s.size();
        int res = 0;
        char pre = ' ';
        for(int i = 0; i < n; ++i) {
            if(mp[pre] < mp[s[i]]) {
                res = res - mp[pre];
                res = res + mp[s[i]] - mp[pre];
            }
            else {
                res = res + mp[s[i]];
            }
            //cout<<res<<endl;
            pre = s[i];
        }
        return res;
    }
};
int main() {
    return 0;
}