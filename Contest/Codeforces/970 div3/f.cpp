#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int mod = 1e9 + 7;
i64 qpow (i64 x, i64 y) {
    i64 res = 1;
    x %= mod;
    for(; y; y >>= 1, x = x * x % mod) {
        if(y & 1) res = (res * x) % mod;
    }
    return res % mod;
}
void solve() {
    i64 n;
    std::cin >> n;
    std::vector<i64> v(n + 1), sum(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
        sum[i] %= mod;
    }
    i64 ans = 0;
    for(int i = 1; i <= n; i++){
        i64 temp = sum[n] - sum[i] + mod;
        temp %= mod;
        temp *= v[i];
        temp %= mod;
        ans += temp;
        ans %= mod;
    }
    i64 p = n * (n - 1) / 2;
    p %= mod;
    i64 inv = qpow(p, mod - 2);
    inv %= mod;
    ans = ans * inv;
    ans %= mod;
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}