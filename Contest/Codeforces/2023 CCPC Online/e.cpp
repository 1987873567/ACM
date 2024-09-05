#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr std::string S = "LURD";
void solve() {
	int n;
	std::string s;
	std::cin >> n >>s;


	std::map<std::pair<int, int>, int> vis;
	std::set<std::pair<int, int>> ans;

	auto dfs=[&](auto &dfs,int p, int x, int y)->void{
		if(p == n){
			ans.insert({x, y});
			return;
		}
		
 		int dx = x + d[S.find(s[p])][0];
		int dy = y + d[S.find(s[p])][1];
		if (vis[{dx, dy}] == 1) {
			dfs(dfs, p + 1, dx, dy);
		} else if(vis[{dx, dy}] == 0){
			vis[{dx, dy}] = 1;
			dfs(dfs, p + 1, dx, dy);
			vis[{dx, dy}] = -1;
			dfs(dfs, p + 1, x, y);
			vis[{dx, dy}] = 0; 
		} else {
			dfs(dfs, p + 1, x, y);
		}
	};
	vis[{0, 0}] = 1;
	dfs(dfs, 0, 0, 0);
	std::cout << ans.size() << '\n';
	for(auto [x, y] : ans){
		std::cout << x << " " << y << "\n";
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