#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::array<i64, 3>> dp(n + 1);
	for (i64 i = 1, x; i <= n; i++){
		std::cin >> x;
		// 0直接+ 1abs 2当前最大 
		dp[i][0] = dp[i - 1][0] + x;
		dp[i][1] = dp[i - 1][2] + x;
		dp[i][2] = std::max(abs(dp[i][0]), abs(dp[i][1]));
	}
	std::cout << dp[n][2] << "\n";
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