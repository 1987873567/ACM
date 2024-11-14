#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
#define int long long
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(a) a.begin(), a.end()
#define CF cout.flush();
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::UNIFORM_INT_DISTRIBUTION<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 1e6;
constexpr int mod = 1e9 + 7;
constexpr ld eps = 1e-6;

void solve() {
	int l1, r1;
	int l2, r2;
	std::cin >> l1 >> r1 >> l2 >> r2;
	int ans = 0;
	
	if (r1 < l2 || r2 < l1) {
		ans = 1;
	} else {
		int l = std::max(l1, l2);
		int r = std::min(r1, r2);
		ans = r - l + 2;
		if (l1 == l2) ans--;
		if (r1 == r2) ans--;
	}
	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

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