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
	int n, a, b, c;
	std::cin >> n >> a >> b >> c;
	std::vector<int> dp(n + 1, -1);
	dp[0] = 0;
	for (int i = 0; i <= n; i++) {
		for (auto j : {a, b, c}) {
			if(i + j > n) continue;
			if(dp[i] != -1) dp[i + j] = std::max(dp[i + j], dp[i] + 1);
		}
	}
	std::cout << dp[n] << "\n"; 
}

int main() {
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