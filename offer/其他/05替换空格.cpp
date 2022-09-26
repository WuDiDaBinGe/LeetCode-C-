#include<bits/stdc++.h>
using namespace std;
// 空间复杂度O(n)
class Solution {
public:
    string replaceSpace(string s) {
        int n = s.size();
        string res = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ')
                res.push_back(s[i]);
            else
                res += "%20";
        }
        return res;
    }
};
// 空间复杂度O(1)
class Solution {
public:
    // 空间复杂度O(1)
    string replaceSpace(string s) {
        int n = s.size(), count = s.size() - 1;
        int  num = 0;
        // 先统计需要在原字符串上增加的数目
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') num += 2;
        }
        while(num) {
            s.push_back(' ');
            num--;n++;
        }
        n = n - 1;
        // 从后向前遍历
        while(count >= 0) {
            if(s[count] == ' '){
                s[n] = '0';
                n--;
                s[n] = '2';
                n--;
                s[n] = '%';
                n--;
            }
            else{
                s[n--] = s[count];
            }
            count--;
        }
        return s;
    }
};