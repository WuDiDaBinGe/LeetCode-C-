#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /* Write Code Here */
    int minimizedMaximum(int n, vector < int > quantities) {
      int m = quantities.size();
      if(m > n) return 0;
      vector<int> dp = quantities;
      for(int i = m + 1; i <= n; ++i) {
        auto pos = max_element(dp.begin(), dp.end());
        int value = *pos;
        if(value == 1) {
            *pos = value / 2;
            dp.push_back(value / 2 + 1);
        } else {
            *pos = value / 2;
            dp.push_back(value / 2);
        }
      }
      return *max_element(dp.begin(), dp.end());
    }
};
int main() {
    int res;

    int n;
    cin >> n;



    int quantities_size = 0;
    cin >> quantities_size;

    vector<int> quantities;
    int quantities_item;
    for(int quantities_i=0; quantities_i<quantities_size; quantities_i++) {
        cin >> quantities_item;

        quantities.push_back(quantities_item);
    }


    Solution *s = new Solution();
    res = s->minimizedMaximum(n, quantities);
    cout << res << endl;
    
    return 0;

}
