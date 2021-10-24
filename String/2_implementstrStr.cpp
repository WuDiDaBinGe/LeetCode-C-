#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int strStr(string haystack, string needle) {
    int hay_len = haystack.length();
    int need_len = needle.length();
    if (need_len==0) return 0;
    if (hay_len==0) return -1;
    for(int i=0;i<=hay_len-need_len;i++){
        int j =0;
        for (j = 0; j < need_len; j++) {
            if (haystack[i+j]==needle[j])
                continue;
            else
                break;
        }
        if (j==need_len)
            return i; 
    }
    return -1;
}
/*
    string match problem
    using kmp algorithm
*/
// compute next[] table
void computeNext(string pattern, vector<int> &nexttable){
    int i;
    int j = -1;
    int m = pattern.length();
    nexttable[0] = j;
    for (i = 1;i < m; i++) {
        while (j > -1 && pattern[j+1] != pattern[i])
            j = nexttable[j];
        if (pattern[j+1] == pattern[i])
            j++;
        nexttable[i] = j;
    }
}
int kmpMatch(string text,string pattern) {
    int i,j=-1;
    int n = text.length();
    int m = pattern.length();
    if (m==0) return 0;
    if (n==0) return -1;
    vector<int> next_table(m,0);
    computeNext(pattern, next_table);
    for (int t=0;t<m;t++) {
        cout<< next_table[t]<<" ";
    }
    cout<<endl;
    for (i=0; i<n; i++) {
        while (j>-1 && pattern[j+1] != text[i]) {
            j = next_table[j];
        }
        if (text[i] == pattern[j+1]) 
            j++;
        if (j==m-1) {
            return i-j;
        }
    }
    return -1;
}
int main(){
    cout<<kmpMatch("mississippi" ,"issipi");
    return 0;
}