#include<bits/stdc++.h>
using namespace std;
bool checkInclusion2(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if(n2 < n1) return false;
    vector<int> mp(26);
    for(int i = 0; i < n1; ++i) 
        mp[s1[i] - 'a']++;
    for(int i = 0; i <= n2 - n1; ++i) {
        vector<int> tmp(26);
        bool flag = true;
        for(int j = i; j < i + n1; ++j) {
            tmp[s2[j] - 'a']++;
            if(tmp[s2[j] - 'a'] > mp[s2[j] - 'a']) {
                flag = false;
                break;
            } 
        }
        if(flag) return true;
    }
    return false;
}
// 优化1 全程记录tmp数组
// 优化2 记录diff记录与mp不同的个数
bool checkInclusion1(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if(n2 < n1) return false;
    vector<int> mp(26);
    for(int i = 0; i < n1; ++i) 
        mp[s1[i] - 'a']++;
    vector<int> tmp(26);
    for(int i = 0; i < n1; ++i) {
        tmp[s2[i] - 'a']++;
    }
    auto check = [&mp, &tmp]()->bool {
        for(int i = 0; i < mp.size(); ++i) {
            if(tmp[i] < mp[i]) return false;
        }
        return true;
    };
    bool flag = check();
    if(flag) return true;
    for(int i = 1; i <= n2 - n1; ++i) {
        tmp[s2[i - 1] - 'a']--;
        tmp[s2[i + n1 - 1] - 'a']++;
        flag = check();
        if(flag) return true;
    }
    return false;
}
// 滑动窗口
bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if(n2 < n1) return false; 
    vector<int> mp(26);
    for(int i = 0; i < n1; ++i) 
        mp[s1[i] - 'a']--;
    int left = 0, right = 0;
    while(right < n2) {
        int c = s2[right]-'a';
        mp[c]++;
        right++;
        while (mp[c] > 0) {
            mp[s2[left] - 'a']--;
            left++;
        }
        if(right - left == n1) {
            return true;
        }
    }
    return false;
}
int main()
{
   cout<<checkInclusion("ab", "eidbaooo")<<endl;
   cout<<checkInclusion("ab", "eidboaoo")<<endl;
   cout<<checkInclusion("adc", "dcda")<<endl;
   return 0;
}