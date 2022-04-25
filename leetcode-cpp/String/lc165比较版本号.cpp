#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        vector<int> v1, v2;
        string temp;
        while(getline(ss1, temp, '.'))
            v1.push_back(stoi(temp));
        while(getline(ss2, temp, '.'))
            v2.push_back(stoi(temp));
        if(v1.size() >= v2.size()) {
            int count = v1.size() - v2.size();
            while(count--)
                v2.push_back(0);
        } else {
            int count = v2.size() - v1.size();
            while(count--)
                v1.push_back(0);  
        }
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] > v2[i]) return 1;
            else if(v1[i] < v2[i]) return -1;
            else continue;
        }
        return 0;
    }
};
int main() {
    return 0;
}