#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int mod = 998244353;


void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> g(n + 1);
	for(int i = 1; i < n; i++){
		int a, b;
		std::cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	std::vector<i64> f(n + 1);
	f[0] = f[1] = 1;
	for(int i = 2; i <= n; i += 2){
		f[i] = f[i - 2] * (i - 1) % mod;
	}
	std::vector<i64> sum(n + 1), dp(n + 1);
	auto dfs = [&](auto &&self, int x, int fa) -> void{
		sum[x] = 1;
		dp[x] = 1;
		int cnt = 0;
		for(auto y : g[x]){
			if(y != fa){
				self(self, y, x);
				sum[x] += sum[y];
				dp[x] = (dp[x] * dp[y]) % mod;
				if(sum[y] & 1) cnt++;
			}
		}
		if(cnt & 1) cnt++;
		dp[x] = (dp[x] * f[cnt]) % mod;
	};
	dfs(dfs, 1, 1);
	std::cout << dp[1] << "\n";
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