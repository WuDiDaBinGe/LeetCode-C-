#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> a(10);
    a[1].push_back(3);
    cout<<a[1].size()<<endl;
    return 0;
}