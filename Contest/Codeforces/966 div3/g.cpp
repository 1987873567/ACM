#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
#define int long long
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(a) a.begin(), a.end()
#define CF cout.flush();
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 1e6;
constexpr int mod = 1e9 + 7;
constexpr ld eps = 1e-6;

int t0, t1, t2, n, m;

int dijkstra(int ps, int pe, auto &g, int k) {
    std::vector<int> dis(n + 1, -1);

    std::priority_queue<PII> q;
    q.push({k, ps});

    while (q.size()) {
        auto [d, x] = q.top();
        q.pop();

        if(dis[x] != -1)continue;
        dis[x] = d;

        for (auto &[y, l1, l2] : g[x]) {
            int bus = -1;
            bus = std::max(bus, std::min(d, t1) - l1);
            if (d - l1 >= t2) {
                bus = std::max(bus, d - l1);
            }
            bus = std::max(bus, d - l2);
            if (bus >= 0) {
                q.emplace(bus, y);
            }
        }
    }
    return dis[pe];
}

void solve() {
    std::cin >> n >> m >> t0 >> t1 >> t2;
    std::vector<std::vector<std::array<int,3>>> g(n + 1);
    for (int i = 0; i < m; i ++) {
        int a, b, l1, l2;
        std::cin >> a >> b >> l1 >> l2;
        g[a].push_back({b, l1, l2});
        g[b].push_back({a, l1, l2});
        // std::cout << a << " " << b << " " << l1 << "\n";
    }
    int ans = dijkstra(n, 1, g, t0);
    std::cout << ans << "\n";

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