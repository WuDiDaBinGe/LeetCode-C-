#include<bits/stdc++.h>
using namespace std;
int main(){
    return 0;
}
class Solution {
  public:
    //Insert one char from stringstream
    queue<char> que;
    unordered_map<char, int> mp;
    int index = 0;
    void Insert(char ch) {
        if (mp.find(ch) == mp.end()) {
            mp[ch] = index;
            que.push(ch);
        } else {
            mp[ch] = -1;
            while(!que.empty() && mp[que.front()] == -1) {
              que.pop();
            }
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
      if(que.empty()) return '#';
      else return que.front();
    }

};
