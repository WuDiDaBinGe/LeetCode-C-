#include<iostream>
#include<string>
using namespace std;
/*
https://leetcode-cn.com/problems/regular-expression-matching/solution/liang-chong-shi-xian-xiang-xi-tu-jie-10-48bgj/https://leetcode-cn.com/problems/regular-expression-matching/solution/liang-chong-shi-xian-xiang-xi-tu-jie-10-48bgj/
*/
bool isMatch(const char *s,const char *p) {
    if(*p=='\0') return *s=='\0';
    // 下一个不是*符的时候
    if (*(p+1)!='*') {
        // 若当前两个匹配 则需要s+1 p+1；若不匹配直接返回false
        if(*p==*s||(*p=='.'&&*s!='\0')) {
            return isMatch(s+1, p+1);
        }
        else
            return false;
    }
    else {
        // 当下一个字符是*的时候 两种情况
        /*
            aa b*
            第一种：当前字符不匹配，则将正则中*之前的忽略掉（b*），然后匹配s与p+2
            aa a*
            第二种：当前字符匹配有两种做法，1.将a* 忽略直接匹配s与p+2 2.另一种匹配s+1 与 p
        */
        while (*s==*p||(*p=='.'&&*s!='\0')) {
            if (isMatch(s, p+2))
                return true;
            s++;
        }
        return isMatch(s,p+2);
    }
}
bool isMatch(string s, string p) {
    return isMatch(s.c_str(),p.c_str());
}

int main() {
    return 0;
}