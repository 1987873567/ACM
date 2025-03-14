#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d4[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
// constexpr int d8[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
/*
1 9 12 4 7 2
1 2 4 7 9 12
*/
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n), b;
    for(int i = 0; i < n; i++){
    	std::cin >> v[i];
    }
    for(int i = 1; i < n; i++){
    	b.push_back(std::abs(v[i] - v[i - 1]));
    }
    std::sort(all(b));
    int ans = 0;
    for(int i = 0; i < b.size() - k + 1; i++){
    	ans += b[i];
    }
    std::cout << ans << "\n";
}

signed main() {
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