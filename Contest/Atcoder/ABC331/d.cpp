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
    int n, q;
    std::cin >> n >> q;
    std::vector<std::string> mp(n);
    std::vector<std::vector<i64>> sum(n + 1, std::vector<i64> (n + 1));
    for(int i = 0; i < n; i++){
        std::cin >> mp[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (mp[i - 1][j - 1] == 'B');
        }
    }
    
    auto Ask = [&](i64 l, i64 r) {
        i64 p = sum[n][n];
        i64 h = l / n, w = r / n;
        i64 res = p * h * w;
        l %= n, r %= n;
        res += w * sum[l][n];
        res += h * sum[n][r];
        res += sum[l][r];
        return res;
    };

    while (q--) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        a++, b++, c++, d++;
        std::cout << Ask(c, d) - Ask(c, b - 1) - Ask(a - 1, d) + Ask(a - 1, b - 1) << "\n";
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