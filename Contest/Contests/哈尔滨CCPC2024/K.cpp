#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

#define int i64

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    std::vector<std::array<i64, 3>> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    std::sort(all(v), std::greater());

    std::vector<i64> sum(n + 1), sum2(n + 1);
    i64 ans = 0, c = m, S = 0;
    for(int i = 1; i <= n; i++){
        sum[i] += sum[i - 1] + (v[i - 1][2] - v[i - 1][1]);
        sum2[i] += sum2[i - 1] + ((v[i - 1][2] - v[i - 1][1]) * v[i - 1][0]);
        S += v[i - 1][0] * v[i - 1][1];
        c -= v[i - 1][1];
    }
    ans = S;
    for(int i = 1; i <= n; i++){
        i64 res = S - v[i - 1][0] * v[i - 1][1];
        i64 t = c + v[i - 1][1];
        auto p = upper_bound(sum.begin(), sum.begin() + i, t) - sum.begin();
        // while(p > 0 && sum[p] > t) p--;
        // if(p == 0) p = 1;
        res += sum2[p - 1];
        t -= sum[p - 1];

        res += t * v[p - 1][0];
        ans = std::max(ans, res);
    }
    std::cout << ans << "\n";


}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}