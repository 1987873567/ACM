#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
const int N = 3300;
i64 dp[N][N], v[N];
void solve() {
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
		dp[i][i] = v[i];
	}
	for(int len = 2; len <= n; len++){
		for(int l = 1; l <= n - len + 1; l++){
			int r = l + len - 1;
			dp[l][r] = std::max(v[l] - dp[l + 1][r], v[r] - dp[l][r - 1]);
		}
	}
	std::cout << dp[1][n] << "\n";
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