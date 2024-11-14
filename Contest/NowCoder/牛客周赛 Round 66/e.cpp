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
    int n, m;
    std::cin >> n >> m;
    std::set<std::pair<i64, i64>> s;
    std::vector<i64> v(n + 1);
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
        v[i] += v[i - 1];
        s.insert({i, i});
    }
    while(m--){
        int op, l, r;
        std::cin >> op >> l;
        if(op == 1){
            std::cin >> r;
            auto p = s.lower_bound({l, -1});
            if(p == s.end() || p->first > l)
                p--;
            auto [L, R] = *p;
            while(p != s.end() && p->first <= r){
                L = std::min(p->first, L);
                R = std::max(p->second, R);
                p = s.erase(p);
            }
            s.insert({L, R});
        } else {
            auto p = s.lower_bound({l, -1});
            if(p == s.end() || p->first > l)
                p--;
            ld ans = ld(1.0) * (v[p->second] - v[p->first - 1]) / (p->second - p->first + 1);
            // std::cout << v[p->second] - v[p->first - 1] << " " << (p->second - p->first + 1) << "\n";
            std::cout << ans << "\n";
        }
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
    std::cout<<std::fixed<<std::setprecision(10);

    while (_--) {
        solve();
    }
    return 0;
}