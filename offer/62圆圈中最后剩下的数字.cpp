#include<bits/stdc++.h>
using namespace std;
// dp
int lastRemaining(int n, int m) {
    int dp = 0;
    for(int i = 2; i < n; i++) {
        dp = (dp + m) % i;
    }
    return dp;
}
int main() {
    return 0;
}