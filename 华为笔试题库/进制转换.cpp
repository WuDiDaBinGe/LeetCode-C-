#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    string snum; cin>>snum;
    snum = snum.substr(2);
    unordered_map<char, int> hash;
    for(int i = 0; i <= 9; i++) {
        hash['0' + i] = i;
    }
    int count = 10;
    for(char c = 'A'; c <= 'F'; c++) {
        hash[c] = count++;
    }
    int res = 0, x = 1;
    for(int i = snum.size() - 1; i >= 0; i--) {
        res += hash[snum[i]] * x;
        x = 16 * x;
    }
    cout<<res<<endl;
    return 0;
}