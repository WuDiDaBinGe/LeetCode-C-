#include<bits/stdc++.h>
using namespace std;
int petalsBreak(vector<int>& petals) {
    int n = petals.size();
    int sum = 0, count = 0;
    for(int i = 0; i < petals.size(); i++) {
        if(petals[i] == 1) 
            count++;
        else if(petals[i] == 2)
            count++;
        else {
            count += petals[i] / 2;
            if(petals[i] % 2) count++;
        }
    }
    return count;
}
int main() {
    return 0;
}