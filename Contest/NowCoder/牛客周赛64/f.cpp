#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
struct LCA {
    std::vector<std::vector<int>> g, fa;
    std::vector<int> tin, tout, dis;
    int n, maxLog, timer;

    LCA(int n, std::vector<std::vector<int>>& adj, int root) {
        this->n = n;
        std::swap(this->g, adj);
        maxLog = log2(n) + 1;
        this->timer = 0;
        dis.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        fa.assign(n, std::vector<int>(maxLog + 1));
        dfs(root, root);
    }
    void dfs(int v, int p) {
        tin[v] = ++timer;
        fa[v][0] = p;
        for (int i = 1; i <= maxLog; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        }
        for (auto &u : g[v]) {
            if (u != p) {
                dis[u] = dis[v] + 1;
                dfs(u, v);
            }
        }
        tout[v] = ++timer;
    }


    bool is_father(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int query_lca(int u, int v) {
        if (is_father(u, v)) return u;
        if (is_father(v, u)) return v;
        for (int i = maxLog; i >= 0; i--) {
            if (!is_father(fa[u][i], v)) {
                u = fa[u][i];
            }
        }
        return fa[u][0];
    }
    int q_dis(int u, int v) {
        if (is_father(u, v)) return 0;
        if (is_father(v, u)) return dis[u] - dis[v];
        int res = 0;
        for(int i = maxLog; i >= 0; i--) {
            if (!is_father(fa[u][i], v)) {
                u = fa[u][i];
                res += (1 << i);
            }
        }
        return res + 1;
    }
    int q_tow_dis(int u, int v){
    	return dis[u] + dis[v] - dis[query_lca(u, v)] * 2;
    }
    int q_fa_kth(int x, int len){
        for(int i = maxLog; i >= 0; i--){
            if(len >> i & 1){
                x = fa[x][i];
            }
        }
        return x;
    }
    int q_dis_one(int x){
    	return dis[x];
    }
};
void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<std::vector<int>> g(n);
	for(int i = 1; i < n; i++){
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	std::vector<i64> size(n), sum(n), dp(n);

	auto dfs = [&] (auto &&self, int x, int fa) -> void{
		size[x] = 1;
		for(auto y : g[x]){
			if(y ^ fa){
                sum[y] = sum[x] + 1;
                dp[0] += sum[y];
				self(self, y, x);
				size[x] += size[y];
			}
		}
	};

	dfs(dfs, 0, 0);

	auto dfs1 = [&](auto &&self, int x, int fa) -> void{
		for(int y : g[x]){
			if(y ^ fa){
				dp[y] = dp[x] + n - size[y] * 2;
				self(self, y, x);
			}
		}
	};

	dfs1(dfs1, 0, 0);

	LCA lca(n, g, 0);

	while(q--){
		int a, b;
		std::cin >> a >> b;
		a--, b--;
        // std::cout /*<< sum[a] << " " << sum[b] << " "*/ << dp[a] << " " << dp[b] << " " << lca.q_tow_dis(a, b) << "\n";
		std::cout << (dp[a] + dp[b] - 1ll * n * lca.q_tow_dis(a, b)) / 2 << "\n";
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