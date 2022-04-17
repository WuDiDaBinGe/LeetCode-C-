#include<iostream>
using namespace std;
int mySqrt(int x) {
    if(x == 1 || x == 0) return x; 
    int left = 1, right = x / 2;
    while(left <= right) {
        int mid = (left + right) / 2;
        if((long long)mid * mid <= x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return right;
}
int main() {
    cout<<mySqrt(4)<<endl;
    cout<<mySqrt(2147395599)<<endl;
    return 0;
}