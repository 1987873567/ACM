#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

std::vector g(3300, std::vector<int>()); 
std::vector vis(3300, std::set<int>()); 
void solve() {
	int n;
	std::cin >> n;
	for(int i = 1, x; i <= n; i++){
		std::cin >> x;
		g[x].push_back(i);
		vis[x].insert(i);
	}
	int ans = 1;
	for(int i = 1; i <= 3000; i++){
		if(g[i].size() == 0) continue;
		for(int j = 0; j < g[i].size() - 1; j++){
			int res = 0, x = g[i][j], d = g[i][j + 1] - g[i][j];
			while(vis[i].count(x)){
				res ++;
				x += d;
			}
			ans = std::max(ans, res);
		}
	}
	std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}