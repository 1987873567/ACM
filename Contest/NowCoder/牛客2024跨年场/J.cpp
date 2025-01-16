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
	int n;
	std::string s = "GL", S = "", choice = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";
	std::cin >> n;
	for(int i = 0; i < n; i++){
		S += s;
	}
	std::string ans = S;
	// for(int i = 0; i < S.size(); i += 6){
	// 	std::bitset<6> x(S.substr(i, 6));
	// 	int p = x.to_ullong();
	// 	ans += choice[p];
	// }
	// std::reverse(all(ans));
	std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}