#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
int main() {
    string line;
    getline(cin, line);
    string x;
    stringstream ss(line);
    while(ss>>x);
    //while(getline(ss, x, ','));
    cout<<x.size()<<endl;
    return 0;
}