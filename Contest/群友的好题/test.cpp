#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5, M = 20;
vector<int> linker[N];
int d[N], f[N][M], sz[N], g[N];

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    for (int i = 1, u, v; i < n; ++i) {
    	cin >> u >> v;
    	linker[u].push_back(v);
    	linker[v].push_back(u);
    }
    
    auto dfs1 = [&](auto self, int u, int fu) -> void {
    	for (int v : linker[u]) {
    		if (v != fu) {
    			d[v] = d[u] + 1, f[v][0] = u, sz[v] = 1, g[1] += d[v];
			    for (int i = 1; i < M; ++i) {
			    	f[v][i] = f[f[v][i - 1]][i - 1];
			    }
    			self(self, v, u);
    			sz[u] += sz[v];
    		}
    	}
    };
    sz[1] = 1;
    dfs1(dfs1, 1, 0);
    
    auto dfs2 = [&](auto self, int u, int fa) -> void {
    	for (int v : linker[u]) {
    		if (v != fa) {
    			g[v] = g[u] + n - sz[v] * 2;
    			self(self, v, u);
    		}
    	}
    };
    dfs2(dfs2, 1, 0);
    
    while (q--) {
    	auto lca = [&](int x, int y) -> int {
    		if (d[x] < d[y]) {
    			swap(x, y);
    		}
    		for (int i = M - 1; i >= 0; --i) {
    			if (d[f[x][i]] >= d[y]) {
    				x = f[x][i];
    			}
    		}
    		if (x == y) {
    			return x;
    		}
    		for (int i = M - 1; i >= 0; --i) {
    			if (f[x][i] != f[y][i]) {
    				x = f[x][i], y = f[y][i];
    			}
    		}
    		return f[x][0];
    	};
    	
    	int x, y;
    	cin >> x >> y;
    	int key = d[x] + d[y] - d[lca(x, y)] * 2;
        std::cout << g[x] << " " << g[y] << " " << key << "\n";
    	cout << (g[x] + g[y] - key * n) / 2 << '\n';
    }
    
    return 0;
}    
