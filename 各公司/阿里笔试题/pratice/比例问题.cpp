#include<bits/stdc++.h>
using namespace std;
int main(){
    int A, B, a, b;
    cin>>A>>B>>a>>b;
    long long  right1 = A * b;
    long long  right2 = B * a;
    long long boder_right = min(right1, right2);
    long long boder_left = max(a, b);
    //cout<<boder_left<<"  r:"<<boder_right<<endl;
    if(boder_left > boder_right) {
        cout<<0<<" "<<0<<endl;
    } else {
        // 二分查找
        long long count = boder_right / (a * b);
        long long maxNum = a * b * count;
        if(maxNum >= boder_left && maxNum <= boder_right) {
            cout<<(long long)maxNum / b<<" "<<(long long)maxNum / a<<endl;
        } else {
            cout<<0<<" "<<0<<endl;
        }
    }
    return 0;
}