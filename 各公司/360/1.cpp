#include<bits/stdc++.h>
using namespace std;

int main()
{
   string source, target;
   cin>>source;
   cin>>target;
   int s_a = 0, t_a = 0;
   int same = 0; 
   for(int i = 0; i < source.size(); ++i) {
        if(source[i] == 'A') {
            s_a++;
            if(target[i] == 'A') {
                same++;
                t_a++;
                continue;
            }
        }
        if(target[i] == 'A') 
            t_a++;
   }
   if(s_a > t_a) {
        cout<<s_a - same<<endl;
   } else {
        cout<<t_a - same<<endl;
   }
   return 0;
}