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
	int n, q;
	std::string s;
	std::cin >> n >> q >> s;
	s = ' ' + s;
	std::vector<int> sum(n + 2), suf(n + 2), pre(n + 2);
	for (int i = 1; i <= n; i++) {
		if(s[i] == '1') pre[i] = pre[i - 1] + 1; 
	}
	for (int i = n; i >= 1; i--) {
		if(s[i] == '1') suf[i] = suf[i + 1] + 1; 
	}
	for (int i = 1; i <= n; i++) {
		sum[i] += sum[i - 1] + (pre[i] & 1);
	}
	auto cal = [&](int l, int r) {
		int x = l + suf[l], y = r - pre[r];
		if(x >= y) return r - l;
		return (suf[l] + pre[r] + 1) / 2 + sum[y] - sum[x - 1];
	};
	while(q--){

		int l, r;
		std::cin >> l >> r;

		std::cout << std::max(0, (r - l + 1) / 3 - cal(l, r)) << '\n';
	}
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