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
	std::cin >> n;
	int nn = n - 5;
	int t = n / 7, t1 = nn / 7;
	int a = std::max(0, t1 * 2 + std::min(2, nn - t1 *7));
	int b = t * 2 + std::min(2, n - t * 7);
	// int a = std::max(0, std::min(n - 5, (n + 1) / 7 * 2));
	// int b = std::min(n, (n + 6) / 7 * 2);
	std::cout << a << " " << b <<'\n';
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