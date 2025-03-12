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
	i64 n, x;
	std::cin >> n >> x;
	std::vector<i64> v(n + 1), dp(n + 1, -1e10);
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
		v[i] += v[i - 1];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			dp[i - j + 1] = std::max(dp[i - j + 1], v[i] - v[j - 1]);
		}
	}
	for(int i = 0; i <= n; i++){
		i64 ans = 0;
		for(int j = 1; j <= n; j++){
			ans = std::max(ans, dp[j] + x * std::min(i, j));
		}
		std::cout << ans << " \n"[i == n];
	}
	// std::cout << max << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}