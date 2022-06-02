#include<bits/stdc++.h>
using namespace std;
bool hasSameChar(string& w1, string& w2){
    vector<int> cs(26);
    string temp;
    if(w1.size() > w2.size())
        swap(w1, w2);
    for(int i = 0; i < w1.size(); ++i) 
        cs[w1[i] - 'a']++;
    for(int j = 0; j < w2.size(); ++j) 
        if(cs[w2[j] - 'a'] > 0) return true;
    return false;
}
int maxProduct(vector<string>& words) {
    int res = 0;
    int n = words.size();
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            string w1 = words[i], w2 = words[j];
            int l1 = w1.size(), l2 = w2.size();
            if(l1 * l2 <= res) continue;
            if(!hasSameChar(w1, w2)) res = max(res, l1 * l2);
        }
    }
    return res;
}
int main() {
    return 0;
}