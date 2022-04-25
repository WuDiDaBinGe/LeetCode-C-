#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
// 滑动窗口
int main() {
    string s;cin>>s;
    int n = s.size();
    unordered_map<char, int> window;
    unordered_set<char> need = {'a', 'b', 'c', 'x', 'y', 'z'};
    int left = 0, right = 0;
    while (right < n) {
        if(need.find(s[right]) == need.end()){
            right++;
            continue;
        }
        

    }
    
    return 0;
}