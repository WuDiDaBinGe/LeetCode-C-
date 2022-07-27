#include<bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    int n1 = s.size(), n2 = p.size();
    vector<int> res;
    if(n1 < n2) return res;
    int left = 0, right = 0;
    vector<int> mp(26);
    for(int i = 0; i < n2; ++i)
        mp[p[i] - 'a']--;
    while(right < n1) {
        char c = s[right] - 'a';
        mp[c]++; right++;
        while(mp[c] > 0) {
            mp[s[left] - 'a']--;
            left++;
        }
        if(right - left == n2) {
            res.push_back(left);
        }
    }
    return res;
}
int main()
{
   
   return 0;
}