#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
    int len = s.length();
    int i=0;
    int sign =1;
    int num=0;
    while (s[i]==' '&&i<len) {
        i++;
    }
    if(s[i]=='-'){
        sign=-1;
        i++;
    }
    else if (s[i]=='+')
        i++;
    for (;i<len;i++) {
        if(s[i]>'9'||s[i]<'0')
            break;
        // 判断是否超过边界
        if ((num>INT_MAX/10)||
            ((num == INT_MAX/10)&&(s[i]-'0')>INT_MAX%10)) {
                return sign==-1?INT_MIN:INT_MAX;
            }
        num = num*10 + (s[i]-'0');
    }
    return num*sign;
}

int main() {
    cout<<myAtoi("+1234")<<endl;
    cout<<myAtoi("  ")<<endl;
    cout<<myAtoi("words and 987")<<endl;
    cout<<myAtoi("4193 with words")<<endl;
    cout<<myAtoi("-91283472332")<<endl;
    return 0;
}