#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    std::vector<i64> sum(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
    }
    std::sort(v.begin() + 1, v.end());
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + v[i];
    }
    if (sum[n] <= m) {
        std::cout << "infinite\n";
    } else {
        i64 l = 0, r = 1e9;
        while (l + 1 < r) {
            i64 mid = (l + r) / 2;
            int p = std::lower_bound(v.begin() + 1, v.end(), mid) - v.begin();
            p = std::min(n, p);
            while (p && v[p] >= mid) p--;
            i64 s = sum[p] + (n - p) * mid;
            if (s <= m) {
                l = mid;
            } else {
                r = mid;
            }
        }
        std::cout << l << '\n';
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}