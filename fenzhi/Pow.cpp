#include<iostream>
using namespace std;
double pows(double x, int n) {
    if(n == 0) return 1;
    double v = pows(x, n / 2);
    if(n % 2 == 0) return v * v;
    else return v * v * x;
}
double myPow(double x, int n) {
    if(n < 0) return 1.0 / pows(x, n);
    return pows(x, n);
}

int main() {
    cout<<myPow(2.000, 10)<<endl;
    return 0;
}