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
constexpr int N = 1e6;

i64 qpow(i64 x, i64 y) {
	i64 res = 1;
	for (; y; y >>= 1, x = x * x % mod) {
		if(y & 1) res = res * x % mod;
	}
	return res % mod;
}

i64 fxx[N + 10], dep[N + 10], cnt[N + 10], f[N + 10];
std::vector<std::vector<i64>> g(N + 1);

void dfs(i64 x, i64 fa){
	for(auto y : g[x]) {
		if (y ^ fa) {
			fxx[y] = x;
			dep[y] = dep[x] + 1;
			dfs(y, x);
		}
	}
}

i64 find(i64 x) {
	while(x != f[x]){
		x = f[x] = f[f[x]];
	}
	return x;
}

void add(i64 x, i64 y){
	x = find(x), y = find(y);
	if(dep[x] < dep[y])std::swap(x, y);
	if(x != y){
		f[x] = y;
		cnt[y] += cnt[x];
		cnt[y] %= mod;
	}
}

void solve() {
	i64 n;
	std::cin >> n;
	std::vector<std::pair<i64,i64>> op(n - 1);

	for(auto &[x, y] : op) std::cin >> x >> y;

	

	for(int i = 0; i <= n; i++) f[i] = i, cnt[i] = 1;

	for(i64 i = 1; i < n; i++){
		i64 a, b;
		std::cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dep[1] = 1;
	dfs(1, 0);

	i64 ans = 1;

	for (auto &[x, y] : op) {
		x = find(x), y = find(y);

		if(find(fxx[x]) != y &&  x != find(fxx[y])) 
			return std::cout << 0 << "\n",void();

		ans *= cnt[x] * cnt[y];
		ans %= mod;
		add(x, y);
	}

	ans = qpow(ans, mod - 2) % mod;
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