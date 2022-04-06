#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
double distTwo(int x1, int y1, int x2, int y2) {
    return sqrt(
        pow(x1 - x2 , 2) + pow(y1 - y2, 2)
    );
}
int main() {
    int xa, ya, xb, yb, xc, yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    double AB = distTwo(xa, ya, xb, yb);
    double BC = distTwo(xb, yb, xc, yc);
    double CA = distTwo(xa, ya, xc, yc);
    int va, da, vb, db;
    cin>>va>>da>>vb>>db;
    if(va == vb && da == db){
        cout<<-1<<endl;
        return 0;
    }
    double BCCA = CA + BC;
    cout<<BCCA<<endl;
    // 同向 考虑 va == vb的情况
    if(da == db) {
        double t1 = BCCA / abs(va - vb);
        double t2 = AB / abs(va - vb);
        if(da == 1) {
            if(va > vb) cout<<t1<<endl;
            else if(va < vb) cout<<t2<<endl;
        } 
        else{
            if(va > vb) cout<<t2<<endl;
            else if(va < vb) cout<<t1<<endl;
        }
    }
    // 反向
    else {
        double t1 = BCCA / (va + vb + 0.0) ;
        double t2 = AB / (va + vb + 0.0) ;
        if(da == 0 && db == 1)
            cout<<t2<<endl;
        else if(da == 1 && db == 0) 
            cout<<t1<<endl;
    }
    return 0;
}