#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
// statiacs the number of pair
// 判断成对的数有几对
// 若成对的字符的长度正好为字符串长度 那么就是2*对数
// 若对数*2 < 小于字符串长度 那么回文串为 2*对数+1
int longestPalindrome(string s) {
    int s_len =s.length();
    if (s_len==1) return 1;
    sort(s.begin(),s.end());
    int res = 0;
    int pre = 0,cur=pre+1;
    while (pre <= s_len-2) {
        if(s[pre] == s[cur]) {
            res++;
            pre=cur+1;
            cur=pre+1;
        }
        else{
            pre++;
            cur++;
        }
    }
    cout<<res<<endl;
    if (2*res<s_len) {
       return 2*res + 1;
    }
    return 2*res;
}
int main() {
    cout<<longestPalindrome("abccccdd")<<endl;
    return 0;
}