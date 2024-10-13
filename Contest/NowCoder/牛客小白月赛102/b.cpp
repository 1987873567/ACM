#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

ld a;
ld dfs(int n){
	if(n == 1)return a;
	return a + (1.0 / dfs(n - 1));
}

void solve() {
	std::cin >> a;

	std::cout << (a + std::sqrt(a * a + 4)) / 2  << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    std::cout<<std::fixed<<std::setprecision(9);

    while (_--) {
        solve();
    }
    return 0;
}