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
    std::vector<int> L, R;
    for(int i = 0; i < n; i++){
        int x;
        char op;
        std::cin >> x >> op;
        if(op == 'L') L.push_back(x);
        else R.push_back(x);
    }
    // std::sort(all(L));
    // std::sort(all(R));
    int ans = 0;
    for(int i = 1; i < L.size(); i++){
        ans += std::abs(L[i] - L[i - 1]);
    }
    for(int i = 1; i < R.size(); i++){
        ans += std::abs(R[i] - R[i - 1]);
    }
    std::cout << ans << '\n';
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