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
	i64 n, a, b, c;
	std::cin >> n;
	std::cin >> a >> b >> c;
    n--;
    std::vector<std::vector<std::array<i64,2>>> g(a);
    std::vector<i64> dis(a, 1e18), vis(a);
    for(int i = 0; i < a; i++){
        g[i].push_back({(i + b) % a, b});
        g[i].push_back({(i + c) % a, c});
    }
    dis[0] = 0;
    std::priority_queue<std::pair<i64, i64>> q;
    q.push({0, 0});
    while(q.size()){
        auto [d, x] = q.top();
        q.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(auto [y, w] : g[x]){
            if(dis[y] > dis[x] + w){
                dis[y] = dis[x] + w;
                q.push({-dis[y], y});
            }
        }
    }
    i64 ans = 0;
    for(int i = 0; i < a; i++) {
        if(dis[i] <= n)
        ans += (n - dis[i]) / a + 1;
        // std::cout << dis[i] << " \n"[i == 3];
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