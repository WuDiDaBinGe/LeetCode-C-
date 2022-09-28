#include<bits/stdc++.h>
using namespace std;
/*
    敏感词匹配 输出最小的 片段
*/
struct Node {
    bool end;
    map<string, Node> child;
};
map<string, Node> mp;

int main()
{   
   string line;
   map<string, Node>* tmp;
   tmp = &mp;
   while (getline(cin, line)) {
        if(line.empty()) break;
        stringstream ss(line);
        string word;
        int count  = 0;
        string last_word;
        while(getline(ss, word, ' ')) {
            tmp = &(*tmp)[word].child;
            last_word = word;
        }
        (*tmp)[word] = true;
        ss.ignore();
   }
   
   return 0;
}