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
	ld p[5];
	for(int i = 0; i < 5; i++)std::cin >> p[i];
	ld ans = 0, P = p[3] + p[4];
	ld p0 = std::pow(1 - P, 10);
	ld p1 = std::pow(1 - P, 9) * 10 * P;
	ans = 1 - p1 - p0;
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
    std::cout<<std::fixed<<std::setprecision(9);

    while (_--) {
        solve();
    }
    return 0;
}