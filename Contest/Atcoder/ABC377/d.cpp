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
    i64 n, m;
    std::cin >> n >> m;
    // std::vector<std::pair<i64, i64>> v(n);
    std::priority_queue<std::pair<i64, i64>, std::vector<std::pair<i64, i64>>, std::greater<>> q;
    q.push({m, m + 1});
    for(int i = 0; i < n; i++){
        int a, b;
        std::cin >> a >> b;
        q.push({b - 1, a});
    }
    i64 ans = 0;
    for(int l = 1; l <= m; l++){
        while(q.size() && q.top().second < l)q.pop();
        i64 r = q.top().first;
        ans += (r - l + 1);
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