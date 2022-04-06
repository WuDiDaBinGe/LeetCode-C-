#include<bits/stdc++.h>
using namespace std;
// 字符串中仅有'A 'B'最少改变次数 使得相邻不重复
// 仅有两种序列符合 ABABABAB 或者 BABABABAB
// https://www.luogu.com.cn/problem/solution/CF219C 题目
int MinOperations(string s) {
    int  n = s.size();
    if(n <= 1) return 0;
    string temp = s;
    int res = 0; 
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            s[i] = (s[i - 1] == 'A' ? 'B':'A');
            res++;
        }
    }
    int res1 = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(temp[i] == temp[i + 1]) {
            temp[i] = (temp[i + 1] == 'A' ? 'B':'A');
            res1++;
        }
    }
    return min(res, res1);
}
int main() {
    cout<<MinOperations("AAABA")<<endl;
    cout<<MinOperations("AA")<<endl;
    cout<<MinOperations("AA")<<endl;
    return 0;
}