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
	int n, k;
	std::cin >> n >> k;
	std::vector<std::array<i64, 2>> dp(n + 1);
	i64 s = 0;
	for(int i = 1, x; i <= n; i++){
		std::cin >> x;
		s += x;
		if(i >= k){
			dp[i][1] = std::max(dp[i - 1][1], dp[i - k + 1][0]) + x;
		}
		dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][0]);
	}
	i64 ans = std::max(dp[n][0], dp[n][1]);
	if(k == 1) ans = s;
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