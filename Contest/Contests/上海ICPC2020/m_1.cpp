#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double ans = 1e18;
        double n, x, v1, y, v2;
        cin >> n >> x >> v1 >> y >> v2;
        double sum = 0;
        if (x > y)
        {
            swap(x, y);
            swap(v1, v2);
        }
        ans = min(max(x / v1, (n + y - 2 * x) / v2), ans);

        ans = min(max((n - x) / v1, y / v2), ans);

        ans = min(ans, (x + n + n - y) / (v1 + v2));

        double l = x, r = y;
        while(r - l > 10-9)
        {
            double mid1 = (r - l) / 3 + l;
            double mid2 = 2 * (r - l) / 3 + l;
            double sum1 = max((2 * mid1 - x) / v1, (n + y - 2 * mid1) / v2);
            double sum2 = max((2 * mid2 - x) / v1, (n + y - 2 * mid2) / v2);
            if (sum1 < sum2)
            {
                r = mid2;
            }
            else
            {
                l = mid1;
            }
        }
        cout << fixed << setprecision(10);
        ans = min(ans, max((2 * l - x) / v1, (n + y - 2 * l) / v2));
        cout << ans << "\n";
    }
    return 0;
}