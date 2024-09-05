#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr std::string S = "PRS";
void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	s = ' ' + s;
	std::vector<std::array<int,3>> dp(n + 1,{0, 0, 0});
	for (int i = 1; i <= n; i++) {
		int id = S.find(s[i]);

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (k != j && k != (id + 1) % 3)
					dp[i][k] = std::max(dp[i][k], dp[i - 1][j] + (k != id));
			}
		}

	}
	std::cout << std::max({dp[n][0],dp[n][1], dp[n][2]}) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}