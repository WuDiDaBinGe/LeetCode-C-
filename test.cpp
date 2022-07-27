// Sample code to read input and write output:

/*
#include <iostream>

using namespace std;

int main() 
{
	char name[20];
	cin >> name;                     // Read input from STDIN
	cout << "Hello " << name;        // Write output to STDOUT
	return 0;
}
*/

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N; cin>>N;
	vector<int> neg(2), pos(2);
	int t;
	for(int i = 0; i < N; ++i) {
		cin>>t;
		if(t < 0) {
			if(-t > neg[0]) {
				neg[1] = neg[0];
				neg[0] = -t;
			} 
			else if(neg[1] < -t && -t <= neg[0]) {
				neg[1] = -t;
			}
		} else {
			if(t > pos[0]) {
				pos[1] = pos[0];
				pos[0] = t;
			} 
			else if(pos[1] < t && t <= pos[0]) {
				pos[1] = t;
			}
		}
	}
	if(N <= 1)  {
		cout<<0<<endl;
		return 0;
	}
	if(N == 2) {
		int res = 0;
		for(auto num:neg) 
			res -= num;
		for(auto num:pos) 
			res += num;
		cout<<res<<endl;
		return 0;
	}
	if(pos[0] * pos[1] >= neg[0] * neg[1]) {
		//cout<<pos[0]<<" "<<pos[1]<<endl;
		cout<<pos[0] + pos[1]<<endl;
	} else {
		cout<<neg[0] + neg[1]<<endl;
	}
	return 0;
}