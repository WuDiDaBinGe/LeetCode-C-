#include<bits/stdc++.h>
using namespace std;
vector<int> GetEndPoint(string order) {
    int n = order.size();
    int x = 0, y = 0, lastCharPos = -1;
    for(int i = 0; i < n; i++) {
        if(order[i] == 'W' || order[i] == 'A' || order[i] == 'S' || order[i] == 'D') {
            int step = 0;
            if(i - lastCharPos == 1) step = 1;
            else step = stoi(order.substr(lastCharPos + 1, i - lastCharPos - 1));
            if(order[i] == 'W') {
                y += step;
            }
            else if(order[i] == 'A') {
                x -= step;
            }
            else if(order[i] == 'S') {
                y -= step;
            }
            else if(order[i] == 'D') {
                x += step;
            }
            lastCharPos = i;
        }else if((order[i] > '9' || order[i] < '0'))
                lastCharPos = i - 1;
    }
    cout<<x<<" "<<y<<endl;
    return vector<int>{x, y};
}

int main(){
    // GetEndPoint("2W2D");
    GetEndPoint("10W+-20D");
    // GetEndPoint("WWWWD");
    return 0;
}