#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int t_a = a, t_b = b; 
    //1
    t_a = t_a * 4;
    int res1 = t_a + t_b;
    //2
    t_a = a, t_b = b;
    t_b = t_b * 4;
    int res2 = t_a + t_b;
    //3 
    t_a = a, t_b = b;
    t_a = t_a * 2;
    t_b = t_b * 2;
    int res3 = t_a + t_b;
    //4
    t_a = a, t_b = b;
    t_b = t_b * 2;
    t_a = t_a * 2;
    int res4 = t_a + t_b;
    int res = res1 + res2 + res3 + res4;
    printf("%.2f", (res + 0.0) / 4);
    return 0;
}