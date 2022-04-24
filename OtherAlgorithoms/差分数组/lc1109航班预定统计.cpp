#include<bits/stdc++.h>
using namespace std;
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> res(n, 0), d(n, 0);
    for(int i = 0; i < bookings.size(); ++i) {
        vector<int> vec = bookings[i];
        d[vec[0] - 1] += vec[2];
        d[vec[1]] -= vec[2];
    }
    res[0] = d[0];
    for(int i = 1; i < n; i++)
        res[i] = res[i - 1] + d[i];
    return res; 
}
int main() {
    return 0;
}