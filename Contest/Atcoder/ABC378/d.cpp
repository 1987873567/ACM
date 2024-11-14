#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::string> mp(n);
	for(int i = 0; i < n; i++)std::cin >> mp[i];
	auto cal = [&](int X, int Y){
		std::vector<std::vector<int>> vis(n, std::vector<int>(m));
		vis[X][Y] = 1;
		int res = 0;
		auto dfs = [&](auto &&self, int x, int y, int K)->void{
			if(K == k){
				res++;
				return;
			}
			for(int i = 0; i < 4; i++){
				int dx = x + d[i][0], dy = y + d[i][1];
				if(dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy] && mp[dx][dy] != '#'){
					vis[dx][dy] = 1;
					self(self, dx, dy, K + 1);
					vis[dx][dy] = 0;
				}
			}
		};
		dfs(dfs, X, Y, 0);
		return res;
	};
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mp[i][j] == '.'){
				ans += cal(i, j);
			}
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