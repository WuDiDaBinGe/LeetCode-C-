#include<bits/stdc++.h>
using namespace std;
int countWord(string message) {
	stringstream ss(message);
	string x;
	int c = 0;
	while(getline(ss, x, ' ')) {
		c++;
	}
	return c;
}
int main() {
	// cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<11.688798<<endl;
	// cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(2)<<0.688798<<endl;
	string a = "yxbs";
	cout<<a.erase(0,2)<<endl;
	return 0;
}