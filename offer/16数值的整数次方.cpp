#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double res;
        if(x == 1) return 1;
        if(n <= 0) {
            if(n == INT32_MIN) {
                res = 1.0 / mypow(x, (unsigned int)(INT32_MAX) + 1);
            }
            else {
                res = 1.0 / mypow(x, -n);
            }
            
        }  
        if(n > 0) res =  mypow(x, n);
        return res;
    }
    double mypow(double x, unsigned int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        double res = mypow(x, n / 2);
        if((int)n % 2 == 0) {
            return res * res;
        } 
        else{
            return res * res * x;
        } 
    }
};