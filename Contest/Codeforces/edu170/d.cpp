#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 2e6;


void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> f{0}, dp{0};
    int s = 0;
    for(int i = 0, r; i < n; i++){
        std::cin >> r;
        if (r > 0) {
            if(r < f.size())f[r]++;
        } else if(r < 0){
            r = s + r;
            if(r >= 0)f[0]++, f[r + 1]--;
        } else {
            for(int j = 1; j <= s; j++){
                f[j] += f[j - 1];
            }
            for(int j = 0; j <= s; j++){
                dp[j] += f[j];
            }
            dp.push_back(0);
            s++;
            for(int j = s; j >= 1; j--){
                dp[j] = std::max(dp[j], dp[j - 1]);
            }
            f.assign(s + 1, 0);
        }
    }
    for(int j = 1; j <= s; j++){
        f[j] += f[j - 1];
    }
    for(int j = 0; j <= s; j++){
        dp[j] += f[j];
    }
    std::cout << *std::max_element(all(dp)) << "\n";     
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