#include<bits/stdc++.h>
using namespace std;
// 使用差分数组
vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
    // 使用map离散化
    map<int, int> diff;
    for(auto& flow:flowers) {
        diff[flow[0]]++;
        diff[flow[1] + 1]--;
    }
    // 对persion进行排序
    int n = persons.size(); 
    vector<int> ans(n);
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j)->bool{return persons[i] < persons[j];});
    auto it = diff.begin();
    int sum = 0;
    for(int i:id) {
        while(it != diff.end() && it->first <= persons[i]) {
            sum += it->second;
            it++;
        }
        ans[i] = sum;
    }
    return ans;
}
// 上面写法的简洁写法
// 使用差分数组
vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
    // 使用map离散化
    map<int, int> diff;
    for(auto& flow:flowers) {
        diff[flow[0]]++;
        diff[flow[1] + 1]--;
    }
    for(int p:persons) diff[p];
    // 差分数组的前缀和
    int cur = 0;
    for(auto& kv:diff) {
        cur += kv.second;
        kv.second = cur;
    }
    vector<int> ans;
    for(int p:persons) {
        ans.push_back(diff[p]);
    }
    return ans;
}
// 使用树状数组模拟维护差分数组的和
class Solution {
private:
    const int N = 1e9;
    map<int, int> tree;
    int lowbits(int x) {
        return x & (-x);
    }
    void add(int index, int k) {
        while(index <= N) {
            tree[index] += k;
            index += lowbits(index);
        }
    }
    int ask(int index) {
        int res = 0;
        while(index >= 1) {
            res += tree[index];
            index -= lowbits(index);
        }
        return res;
    }
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        for(auto& flow:flowers) {
            add(flow[0], 1);
            add(flow[1] + 1, -1);
        }
        vector<int> ans(persons.size());
        int i = 0;
        // 对persion进行排序
        for(int per:persons) {
            ans[i] = ask(per);
            i++;
        }
        return ans;
    }
};
int main() {

}