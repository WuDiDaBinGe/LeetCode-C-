#include<bits/stdc++.h>
using namespace std;
int sumNums(int n) {
    if(n == 1) return 1;
    return sumNums(n - 1) + n;
}
int main() {
    return 0;