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
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> g(n + 1);
	for(int i = 0; i < m; i++){
		int a, b, c;
		std::cin >> a >> b >> c;
		g[a].push_back(b);
		g[b].push_back(a);
		g[b].push_back(c);
		g[c].push_back(b);
		g[c].push_back(a);
		g[a].push_back(c);
	}
	std::vector<int> ans(n + 1, -1), vis(n + 1);
	for(int i = 1; i <= n; i++){
		if(ans[i] == -1){
			std::queue<int> q;
			q.push(i);
			ans[i] = 0;
			while(q.size()){
				auto x = q.front();
				q.pop();
				if(vis[x])continue;
				vis[x] = 1;
				for(auto y : g[x]){
					if(ans[y] == -1){
						ans[y] = 1;
						q.push(y);
					} else {
						if(!vis[y] && ans[x] == ans[y]){
							if(ans[x] == 2) ans[y] = 1;
							else ans[y] = 2;
						}
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		std::cout << ans[i] + 1 << " \n"[i == n];
	}
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