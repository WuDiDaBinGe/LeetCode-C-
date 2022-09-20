#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> huase_mp = {{'S',0}, {'H',1}, {'C',2}, {'D',3}};
unordered_map<string, int> dianshu_mp;
int all_value[15];
int all_huase[4]; 
set<int> set_huase;
set<int> set_value;
vector<pair<int, int>> datas;
bool checkTongHuaShun(){
    int n = datas.size();
    bool b1 = (set_huase.size() == 1);
    bool b2 = ((datas[0].first + n - 1) == datas[n - 1].first) && (set_value.size() == n);
    return b1 && b2;
}
int checkShunZi(){
    int end_value = -1;
    int n = datas.size();
    for(int i = 1; i <= 10; ++i) {
        int end = i + 4;
        bool flag = true;
        bool tonghua = true;
        for(int j = i; j <= end; ++j){
            if(all_value[j] >= 1){
                continue;
            } else {
                flag = false;
            }
            if()

        }
        if(flag) end_value = end; 
    }
    return end_value;
}
bool checkTonghua() {
    for(int i = 0; i < 3; ++i){
        if(all_huase[i] >= 5) return true;
    }
    return false;
}
string showDown(string inHand) {
    for(int i = 2; i <= 10; i++ ) dianshu_mp[to_string(i)] = i;
    dianshu_mp["A"] = 14, dianshu_mp["J"] = 11, dianshu_mp["Q"] = 12, dianshu_mp["K"] = 13;
    stringstream ss(inHand);
    string temp;
    while(getline(ss, temp, ' ')){
        int hua = huase_mp[temp[0]];
        int value = dianshu_mp[temp.substr(1)];
        set_huase.emplace(hua);
        set_value.emplace(value);
        all_huase[hua]++;
        all_value[value]++;
        datas.push_back(make_pair(value, hua));
    }
    int N = datas.size();
    sort(datas.begin(), datas.end());
    int is_shunzi = checkShunZi();
    bool is_tonghua = checkTonghua();
    if(is_shunzi != -1) {
        
        if(is_tonghua) {
            if(is_shunzi == dianshu_mp["A"]) {
                return "HuangJiaTongHuaShun";
            }
            else {
                return "TongHuaShun";
            }
        } else {
            return "ShunZi";
        }
    }
    if(is_tonghua) {
        return "TongHua";
    }
    return "yuxiub";
}

int main(){
    cout<<showDown("S1 SK SQ SJ S10 H10 H9");
    return 0;
}