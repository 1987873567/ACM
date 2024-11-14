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
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> mp(n);
	for(int i = 0; i < n; i++){
		std::cin >> mp[i];
	}
	std::vector<std::vector<int>> vis(n, std::vector<int>(m));
	int flag = 0;
	std::vector<std::pair<int,int>> ans;
	auto dfs = [&](auto &&self, int x, int y, int cnt)->void{
		if(cnt == n * m - 1){
			flag = 1;
			return;
		}
		if(flag) return;
		for(int i = 0; i < 4; i++){
			int dx = x + d[i][0], dy = y + d[i][1];
			if(dx >= 0 && dx < n && dy < m && dy >= 0 && !vis[dx][dy] && mp[dx][dy] != '#'){
				vis[dx][dy] = 1;
				ans.push_back({dx, dy});
				self(self, dx, dy, cnt + 1);
				if(flag) return;
				ans.pop_back();
				vis[dx][dy] = 0;
			}
		}
	};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			vis[i][j] = 1;
			flag = 0;
			ans.clear();
			ans.push_back({i, j});
			dfs(dfs, i, j, 1);
			if(flag){
				for(auto [x, y] : ans){
					std::cout << x + 1 << " " << y + 1 << "\n";
				}
				return;
			}
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
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}