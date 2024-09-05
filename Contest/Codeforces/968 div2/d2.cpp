#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
#define int long long
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(a) a.begin(), a.end()
#define CF cout.flush();
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 1e6;
constexpr int mod = 1e9 + 7;
constexpr ld eps = 1e-6;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n), b(n);
	int ma = 0, mb = 0;

	for (int i = 0, l; i < n; i++) {
		std::cin >> l;
		std::vector<int> cnt(l+2);
		for (int i = 0, x; i < l; i ++) {
			std::cin >> x;
			if (x < l + 2){
				cnt[x] = 1;
			}
		}
		int A = 0, B = 0;
		while (cnt[A]) A++;
		B = A + 1;
		while (cnt[B]) B++;

		ma = std::max(ma, A);
		mb = std::max(mb, B);
		a[i] = A;
		b[i] = B;
	}

	std::vector<int> cnt(mb + 2);
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}

	std::vector<std::vector<int>> g(mb + 2);
	for (int i = 0; i < n; i++) {
		g[a[i]].push_back(b[i]);
	}

	std::vector<int> dp(mb + 2);
	for (int  i = mb; i >= 0;i--){
		dp[i] = i;
		for (auto j : g[i]){
			dp[i] = std::max(dp[i], dp[j]);
		}
		if(cnt[i] > 1) ma=std::max(dp[i],ma);
	}

	int ans = 0;
	for (int i = 0; i <= std::min(mb,m); i++) {
		ans += std::max(dp[i], ma);
	}

	if (mb <= m) {
		ans += (mb + 1) * (m - mb) + (m - mb) * (m - mb - 1) / 2;
	}
	std::cout << ans << "\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}