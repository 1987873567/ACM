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
    i64 n, l, r;
    std::cin >> n >> l >> r;
    std::vector<i64> v(n + 1);
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
    }
    i64 ans = 0;
    for (i64 i = 1, j = 1, sum = 0; j <= n && i <= n;){
        sum += v[j++];
        while(i < j && sum > r) sum -= v[i++];
        if(sum >= l){
            ans++;
            sum = 0;
            i = j;
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

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}