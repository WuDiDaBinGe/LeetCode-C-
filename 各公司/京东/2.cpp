#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getMaxs(map<int, int> mp){
    vector<vector<int>> maxIndex(2, vector<int>(2));
    for(auto item:mp) {
        int key = item.first;
        int value = item.second;
        if(value > maxIndex[0][1]) {
            maxIndex[1][0] = maxIndex[0][0];
            maxIndex[1][1] = maxIndex[0][1];
            maxIndex[0][0] = key;
            maxIndex[0][1] = value;
        } else if(value > maxIndex[1][1]){
            maxIndex[1][0] = key;
            maxIndex[1][1] = value;
        }
    }
    return maxIndex;
}   

int main()
{
   int n;cin>>n;
   vector<int> nums(n);
   map<int, int> even;
   map<int, int> odd;
   for(int i = 0; i < n; ++i) {
        cin>>nums[i];
        if(i % 2) {
            even[nums[i]]++;
        } else {
            odd[nums[i]]++;
        }
   }
   auto evenMaxs = getMaxs(even);
   auto oddMaxs = getMaxs(odd);
   if(evenMaxs[0][0] != oddMaxs[0][0]) {
        n -= evenMaxs[0][1];
        n -= oddMaxs[0][1];
   } else {
       int ops = max(evenMaxs[0][1] + oddMaxs[1][1], evenMaxs[1][1] + oddMaxs[0][1]);
       n -= ops;
   }
   cout<<n<<endl;
   return 0;
}