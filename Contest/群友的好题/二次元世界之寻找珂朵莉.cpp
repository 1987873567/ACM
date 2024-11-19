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
    std::vector<std::pair<int, int>> x(n), y(n), z(n);
    for(int i = 0; i < n; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        x[i] = {a, i};
        y[i] = {b, i};
        z[i] = {c, i};
    }
    std::sort(all(x));
    std::sort(all(y));
    std::sort(all(z));
    int ix, iy, iz;
    ix = iy = iz = 0;
    std::vector<std::array<int, 3>> e;
    for(int i = 1; i < n; i++){
        e.push_back({std::abs(x[i].first - x[i - 1].first),x[i].second, x[i - 1].second});
        e.push_back({std::abs(y[i].first - y[i - 1].first),y[i].second, y[i - 1].second});
        e.push_back({std::abs(z[i].first - z[i - 1].first),z[i].second, z[i - 1].second});
    }
    std::sort(all(e));
    std::vector<int> f(n + 1);
    std::iota(all(f), 0);
    auto find = [&](int x){
        while(x != f[x]){
            x = f[x] = f[f[x]];
        }
        return x;
    };
    i64 ans = 0;
    for(auto [w, a, b] : e){
        int fa = find(a), fb = find(b);
        if(fa != fb){
            ans += w;
            f[fa] = fb;
        }
    }
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
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}