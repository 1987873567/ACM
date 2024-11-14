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
	int n, k;
	std::cin >> n >> k;
	std::vector<int> v(n);
	int m = 0;
	for (int &i:v) std::cin >> i, m = std::max(m, i);

	std::sort(all(v),[&](int x, int y){return x > y;});
	int A = 0, B = 0, s = 0;
	for (int i = 0 ; i < n; i++){
		if(i&1) B += v[i], s += v[i - 1] - v[i];
		else A += v[i];
	}
	std::cout << A - B - std::min(k, s) << '\n';
	// std::cerr << A << " " << B << "\n"; 
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