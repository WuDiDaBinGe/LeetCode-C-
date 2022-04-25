#include<bits/stdc++.h>
using namespace std;
int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string x;
    vector<int> nums;
    while(ss>>x) {
        if(isalpha(x[0])) {
            cout<<x<<" ";
        } else{
            nums.push_back(stoi(x));
        }
    }
    if(nums.size())
        sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++) {
        cout<<nums[i];
        if(i != nums.size() - 1)
            cout<<" ";
    }
    return 0;
}
class Solution {
public:
    string char_and_num_return(string text_source) {
        // write code here
        string res = "";
        stringstream ss(text_source);
        string subs;
        vector<long long> nums;
        vector<string> strs;
        while(ss>>subs) {
            if(isalpha(subs[0])) {
                strs.push_back(subs);
            } else{
                nums.push_back(stoll(subs));
            }
        }
        for(int i = 0; i < strs.size(); i++) {
            res += strs[i];
            if(i != strs.size() - 1) res += " ";
        }
        if(nums.size() > 0 && strs.size() > 0)
            res += " ";
        if(nums.size() > 0) {
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size(); i++) {
                res += to_string(nums[i]);
                if(i != nums.size() - 1) res += " ";
            }
        }
        return res;
    }
};