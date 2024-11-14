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
    std::vector<i64> sum(n + 1), sum2(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++){
        std::cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    for(int i = 1; i <= n; i++){
        sum2[i] = sum[n] - sum[i - 1];
        sum2[i] += sum2[i - 1];
        p[i] = n - i + 1;
        p[i] += p[i - 1];
    }

    auto cal = [&](i64 x){
        if(!x)return 0ll;
        int pp = std::lower_bound(all(p), x) - p.begin();
        i64 res = 0, y = x - p[pp - 1];
        res += sum2[pp - 1];
        res += sum[pp + y - 1] - sum[pp - 1];
        return res;
    };

    int q;
    std::cin >> q;
    while(q--){
        i64 l, r;
        std::cin >> l >> r;
        std::cout << cal(r) - cal(l - 1) << "\n";
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