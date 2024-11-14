#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

i64 qpow(i64 x, i64 y){
    i64 res = 1;
    for(;y; y >>= 1, x = x * x){
        if(y & 1) res = x * res;
    }
    return res;
}

void solve() {
    int r, c, p;
    std::cin >> r >> c >> p;
    ld q = std::pow(0.5, r + c - 2);
    // std::cout << q << "\n";
    auto C = [&](int m, int n){
        if(m < n || m < 0 || n < 0) return (ld)0.0;
        std::map<int, int> c;
        auto f = [&](int x, int m){
            for(int i = 2; i * i <= x; i++){
                while(x % i == 0){
                    c[i] += (m) * 1;
                    x /= i;
                }
            }
            if(x != 1) c[x] += (m) * 1;
        };
        for(int j = m; j >= m - n + 1; j--){
            f(j, 1);
        }
        for(int j = n; j >= 1; j--){
            f(j, -1);
        }
        ld res = 1;
        for(auto [x, y] : c){
            res *= (ld)qpow(x, y);
        }
        return res;
    };
    // std::cout << C(4, 2) << "\n";
    ld ans = 0;
    ld pp = p;
    int sum = c + r - 2;
    r--, c--;
    for(int i = 0; i <= sum; i++){
        ans += pp * std::max(sum - i - c, 0) * C(sum - i, sum - i - c) + pp * std::max(0, i - r) * C(i, i - r);
    }
    std::cout << ans * q << "\n";
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