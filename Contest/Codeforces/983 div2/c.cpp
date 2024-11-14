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
    std::vector<i64> v(n + 1);
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
    }
    std::sort(all(v));
    v.push_back(1e18);
    i64 ans = 1e9;
    for(int i = 3; i <= n; i++) {
        int l = 1, r = i;
        while(l + 1 != r){
            int m = (l + r) >> 1;
            if(v[m] + v[m - 1] > v[i]){
                r = m;
            } else {
                l = m;
            }
        }
        // std::cout << l << "\n";
        ans = std::min(ans, (n - i) + l - 1);
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
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}
