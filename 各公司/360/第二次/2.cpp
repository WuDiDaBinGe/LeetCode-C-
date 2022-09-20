#include<bits/stdc++.h>
using namespace std;
/*
给出一些仅包含正整数，加号，乘号和等号的方程，
请判断这些方程能否通过插入至多一个数位（若原方程成立则可以不插）使得方程成立。
插入一个数位即将方程视为一个字符串，并将一个0到9之间的数插入中间，开头或末尾
6
16=1+2*3
7*8*9=54
1+1=1+22
4*6=22+2
15+7=1+2
11+1=1+5
Yes
Yes
No
Yes
Yes
No
*/
int calculate(string s){
    vector<int> stk;
    char preSign = '+';
    int num = 0;
    int n = s.length();
    for(int i = 0 ; i< n;++i){
        if(isdigit(s[i])) {
            num = num * 10 + int(s[i] - '0');
        }
        if(!isdigit(s[i]) && s[i] != ' ' || i == n - 1){
            switch (preSign)
            {
            case '+':
                stk.push_back(num);
                break;
            case '*':
                stk.back() *= num;
                break;
            default:
                stk.back() /= num;
                break;
            }
            preSign = s[i];
            num = 0;
        }
    }
    return accumulate(stk.begin(), stk.end(), 0);
} 
int main(){
    int n; cin>>n;
    for(int i = 0; i < n; ++i){
        string s; cin>>s;
        stringstream ss(s);
        vector<string> ops;
        string temp;
        while(getline(ss, temp,'=')){
            ops.push_back(temp);
        }
        int num_left =calculate(ops[0]);
        int num_right = calculate(ops[1]);
        
        if(num_left == num_right){
            cout<<"Yes"<<endl;
            continue;
        }
        if(num_left < num_right) {
            bool flag = false;
            for(int j = 0; j <= ops[0].size(); ++j){
                for(int c = 0; c <= 9; ++c){
                    string temp1=ops[0];
                    temp1.insert(j, 1, c + '0');
                    if(calculate(temp1) == num_right) {
                        flag = true;
                        break;
                    }
                }
                if(flag) {
                    break;
                }
            }
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        } else{
            bool flag = false;
            for(int j = 0; j <= ops[1].size(); ++j){
                for(int c = 0; c <= 9; ++c){
                    string temp1=ops[1];
                    temp1.insert(j,1, c + '0');
                    if(calculate(temp1) == num_left) {
                        cout<<"Yes"<<endl;
                        flag = true;
                        break;
                    }
                }
                if(flag) {
                    break;
                }
            }
            if(!flag) cout<<"No"<<endl;
        }
    }
    return 0;
}