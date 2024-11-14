#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) begin(x), end(x)
typedef long long ll;
// void solve(){

// }
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> v(n * 2);
        for (int i = 0; i < n * 2; i++)
        {
            cin >> v[i];
        }
        sort(all(v));
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if (v[2 * i + 1] - v[2 * i] > a)
                f = 0;
        }
        if (!f)
        {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        int curr = -1;
        for (int i = 0; i < 2 * n; i++)
        {
            if (curr == -1)
            {
                curr = i;
                continue;
            }
            if (v[i] - v[curr] <= b)
            {
                ans++;
                curr = -1;
                continue;
            }
            if (i == 2 * n - 1)
            {
                curr = -1;
                continue;
            }
            assert(i != 2 * n - 2);
            if (v[i + 1] - v[i] <= b)
            {
                if (v[i + 2] - v[curr] <= a)
                {
                    ans++;
                    i++;
                }
                else
                    curr = -1;
            }
            else
                curr = -1;
        }
        cout << ans << '\n';
    }

    return 0;
}