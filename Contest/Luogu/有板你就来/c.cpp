#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int mp[1101][1101], dp[1101][1101];
void solve() {
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			std::cin >> mp[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if((i + j) % 2 == 0){
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + mp[i][j];
			}
			dp[i][j] = std::max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
		}
	}
	std::cout << dp[n][n] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}