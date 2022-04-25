#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
    int M; cin>>M;
    int N; cin>>N;
    vector<float> cap(M, 10);
    int index = -1, p_index = -1;
    for(int i = 0; i < N; i++) {
        char c ; cin>>c;
        for(int j = 0; j < M; j++) {
            if(cap[j] >= 2.5 && c == 'A') {
                p_index = 4 - cap[j] / 2.5; 
                cap[j] -= 2.5;
                index = j;
                break;
            }
            else if(cap[j] >= 10 && c == 'B') {
                cap[j] -= 10;
                index = j;
                p_index = 0;
                break;
            }
            else {
                index = -1; p_index = -1;
            }
        }
    }
    cout<<index + 1<<" "<<p_index + 1<<endl;
    return 0;
}