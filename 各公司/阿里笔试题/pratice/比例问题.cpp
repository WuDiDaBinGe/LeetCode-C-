#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if(b > a) swap(a, b);
    while(b) {
        int temp = a % b;
        a = b;
        b =temp;
    }
    return a;
}
int main(){
    int A, B, a, b;
    cin>>A>>B>>a>>b;
    int gcdn = gcd(a, b);
    a = a / gcdn, b = b / gcdn;
    int unit = min(A / a, B / b);
    cout<<unit * a<<" "<<unit * b<<endl;
    return 0;
}