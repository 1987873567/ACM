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

i64 qpow(i64 x, i64 y){
	i64 res = 1;
	for(;y;y >>= 1, x = x * x % mod){
		if(y & 1) res = res * x % mod;
	}
	return res;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> g(n);
	std::vector<i64> dp(n), dep(n), r(n), sum(n + 1);
	for(int i = 1; i < n; i++){
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
		r[a]++;
		r[b]++;
	}
	dep[0] = 1;
	auto dfs1 = [&](auto &dfs1, int x)->void{
		for(auto y : g[x]){
			if(!dep[y]){
				dep[y] = dep[x] + 1;
				sum[x]++;
				dfs1(dfs1, y);
			}
		}
	};
	dfs1(dfs1, 0);

	std::queue<int> q;
	q.push(0);
	dp[0] = 1;
	while(q.size()){
		int x = q.front();
		q.pop();
		for(int y : g[x]){
			if(!dp[y]){
				dp[y] = (dp[x] * sum[x]) % mod;
				q.push(y);
			}
		}
	}

	i64 ans = 0;
	for(int i = 1; i < n;i++){
		if(r[i] == 1){
			ans += dep[i] * qpow(dp[i], mod - 2);
			ans %= mod;
		}
	}
	std::cout << ans << "\n";

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