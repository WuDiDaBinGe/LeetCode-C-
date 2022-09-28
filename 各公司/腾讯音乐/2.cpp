#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> nums, int x) {
    int n = nums.size();
    long long ans = 0;
    vector<vector<int>> cnts(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        int num = nums[i];
        while(num % 2 == 0) {
            cnts[i][0]++;
            num/=2;
        }
        while(num % 5 == 0) {
            cnts[i][1]++;
            num /= 5;
        }
    }
    int l = 0;
    int r = 0;
    long long t = 0, f = 0;
    while(r < n) {
        t += cnts[r][0];
        f += cnts[r][1];
        r++;
        if (min(t, f) >= x) break;
    }
    if (min(t, f) >= x) ans = (ans + (n - r + 1)) % (1e9+7);
    while(l < r) {
        t -= cnts[l][0];
        f -= cnts[l][1];
        l++;
        while(r < n) {
            if (min(t, f) >= x) break;
            t += cnts[r][0];
            f += cnts[r][1];
            r++;
        }
        if (min(t, f) >= x) if (min(t, f) >= x) ans = (ans + (n - r + 1)) % (1e9+7);
    }
    return ans;
}
int main() {
    vector<int> nums = {5, 2, 3, 50, 4};
    int x = 2;
    cout<<solution(nums, x)<<endl;
    return 0;
}