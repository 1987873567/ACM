#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
#define int long long
void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(auto &i : a)std::cin >> a[i];
	std::map<int, int> b;
	for(int i = 0, x; i < n; i++){
		std::cin >> x;
		b[x]++;
	}
	int ans = 0, flag = 0;
	for(auto [i, j] : b){
		if(j == 1) flag = 1;
		else ans += (j + 1) / 2;
	}
	if(flag)ans = -1;
	std::cout << ans << "\n";
}

signed main() {
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