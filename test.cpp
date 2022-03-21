#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> V(n + 1), ans(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> V[i];
    stack<int> S;
    for (int i = 1; i <= n; ++i)
    {
        while (!S.empty() && V[S.top()] < V[i])
        {
            ans[S.top()] = i;
            cout<<V[S.top()]<<" ";
            S.pop();
        }
        S.push(i);
    }
    cout<<endl;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}