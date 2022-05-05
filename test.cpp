#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<string> a = {"abcd", "a bcd", "abc d", "abbcd"};
	sort(a.begin(), a.end());
	a.push_back("aaaa");
	for(string s : a) {
		cout<<s<<"|";
	}
	return 0;
}