#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n; cin>>n;
   string line;
   cin.ignore();
   set<string> set_word;
   for(int i = 0; i < n; ++i) {
        getline(cin, line);
        stringstream ss(line);
        string word;
        while(getline(ss, word, ' ')) {
            set_word.insert(word);
        }
   }
   int characs = 50;
   for(set<string>::iterator it = set_word.begin(); it != set_word.end(); it++) {
        int n = (*it).size();
        if(characs >= n) {
            cout<<*it<<" ";
            characs -= (n + 1);
        } else {
            cout<<endl;
            cout<<*it<<" ";
            characs = 50 - (n + 1);
        }
        // cout<<*it<<" ";
   }
   return 0;
}