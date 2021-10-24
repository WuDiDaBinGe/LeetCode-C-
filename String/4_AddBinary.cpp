#include<iostream>
#include<string>
using namespace std;
string addBinary(string a, string b) {
    int a_len = a.length();
    int b_len = b.length();
    if(a_len==0) return b;
    else if(b_len==0) return a;
    
    //a.len > b.len (a is always lengther than b)
    if(a_len<b_len){
        string temp=a;
        a=b;
        b=temp;
    }
    a_len = a.length();
    b_len = b.length();
    int a_ptr=a_len-1;
    int b_ptr=b_len-1;
    int cow=0;
    int value =0;
    cout<<a<<" "<<b<<endl;
    cout<<a_len<<" "<<b_len<<endl;
    while (b_ptr>=0 && a_ptr>=0) {
        value = (a[a_ptr]-'0')+(b[b_ptr]-'0')+cow;
        cow = value /2;
        a[a_ptr] = '0'+value%2;
        b_ptr--;
        a_ptr--;
    }
    while (a_ptr>=0) {
        value = (a[a_ptr]-'0') + cow;
        a[a_ptr] = '0'+value%2;
        cow = value /2;
        a_ptr--;
    }
    if(cow > 0)
        a.insert(0, 1, '1');
    cout<<a<<endl;
    return a;
}
int main() {
    addBinary("1111", "1");
    return 0;
}