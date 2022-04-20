#include<bits/stdc++.h>
using namespace std;
int strToInt(string str) {
    int n = str.size();
    // 去除空白字符
    int i = 0;
    while(str[i] == ' ') {
        i++;
    }
    int res = 0, negFlag = 1;
    // 检查首个非空字符是否合法
    if(str[i] == '-') {
        negFlag = -1;
        i++;
    }
    else if(str[i] == '+')
        i++;
    for(; str[i] >= '0' && str[i] <='9'; ++i) {
        // 难点：检查是否越界
        int maxHeight = INT_MAX / 10;
        if(maxHeight < res || (maxHeight / 10 == res && INT_MAX % 10 < (str[i] - '0'))) {
            return negFlag == -1 ? INT_MIN : INT_MAX;
        }
        res = res * 10;
        res = res + (str[i] - '0');
    }
    return negFlag * res;
}
int main() {
    cout<<strToInt("+1234")<<endl;
    cout<<strToInt("  ")<<endl;
    cout<<strToInt("words and 987")<<endl;
    cout<<strToInt("4193 with words")<<endl;
    cout<<strToInt("-91283472332")<<endl;
    return 0;
}