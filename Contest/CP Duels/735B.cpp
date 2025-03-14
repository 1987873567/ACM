#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d4[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
// constexpr int d8[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    if(a > b) std::swap(a, b);
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
    	std::cin >> v[i];
    }
    std::sort(all(v), std::greater<>());
    int i = 0;
    i64 s1 = 0, s2 = 0;
    for(;i < a; i++){
    	s1 += v[i];
    }
    for(;i < a + b; i++){
    	s2 += v[i];
    }
    ld ans = 1.0 * s1 / a + 1.0 * s2 / b;
    std::cout << ans << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    std::cout << std::fixed << std::setprecision(9);

    while (_--) {
        solve();
    }
    return 0;
}