#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
#define int long long
#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(a) a.begin(), a.end()
#define CF cout.flush();
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 1e6;
constexpr int mod = 1e9 + 7;
constexpr ld eps = 1e-6;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<PII> m(n);
    int S = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        S += a + b;
        m[i] = (std::minmax(a, b));
    }

    if (S < k) return std::cout << "-1\n", void();

    std::vector<int> dis(200, 1e18);

    dis[0] = 0;
    int v = 0;
    for (auto [a, b] : m) {
        int c = 0, val = 0;
        v += a + b;
        auto dp = dis;
        while (!(a == 1 && b == 1)) {
            if(a > b) std::swap(a, b);
            c += 1;
            val += a;
            b--;

            for (int i = std::min(v, k); i >= 0; i--) {
                dis[i] = std::min(dis[i], dp[std::max(0ll, i - c)] + val);
            }
            assert(c);
        }
        c += 2;
        val += 1;
        for (int i = std::min(v, k); i >= 0; i--) {
            dis[i] = std::min(dis[i], dp[std::max(0ll, i - c)] + val);
        }
    }

    std::cout << dis[k] << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}