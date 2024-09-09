#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
const int N =  110;

template <class T>
struct Flow{
	struct _Edge{
		int to;
		T cap;
		_Edge(int to, T cap) : to(to), cap(cap) {}
	};
	int n;
	std::vector<_Edge> e;
	std::vector<std::vector<int>> g;
	std::vector<int> cur, h;
	Flow(){}
	Flow(int n){
		init(n);
	}
	void init(int n){
		this->n = n;
		e.clear();
		g.assign(n, {});
		cur.resize(n);
		h.resize(n);
	}

	bool bfs(int s, int t) {
		h.assign(n, -1);
		std::queue<int> que;
		h[s] = 0;
		que.push(s);
		while(!que.empty()){
			const int u =que.front();
			que.pop();
			for (int i : g[u]) {
				auto [v, c] = e[i];
				if(c > 0 && h[v] == -1) {
					h[v] = h[u] + 1;
					if (v == t) {
						return true;
					}
					que.push(v);
				}
			}
		}
		return false;
	}

	T dfs(int u, int t, T f) {
		if(u == t) return f;
		auto r = f;
		for(int &i = cur[u]; i < int(g[u].size()); ++i) {
			const int j = g[u][i];
			auto [v, c] = e[j];
			if (c > 0 && h[v] == h[u] + 1) {
				auto a = dfs(v, t, std::min(r, c));
				e[j].cap -= a;
				e[j ^ 1].cap += a;
				r -= a;
				if(r == 0) return f;
			} 
		}
		return f - r;
	}

	void add(int u, int v, T c) {
		g[u].push_back(e.size());
		e.emplace_back(v, c);
		g[v].push_back(e.size());
		e.emplace_back(u, 0);
	}

	T flow(int s, int t) {
		T ans = 0;
		while(bfs(s, t)) {
			cur.assign(n, 0);
			ans += dfs(s, t, std::numeric_limits<T>::max());
		}
		return ans;
	}

	std::vector<bool> minCut() {
		std::vector<bool> c(n);
		for(int i = 0; i < n; i++){
			c[i] = (h[i] != -1);
		}
		return c;
	}
	struct Edge{
		int from, to;
		T cap, flow;
	};
	std::vector<Edge> edges() {
		std::vector<Edge> a;
		for(int i = 0; i < e.size(); i += 2) {
			Edge x;
			x.from = e[i + 1].to;
			x.to = e[i].to;
			x.cap = e[i].cap + e[i + 1].cap;
			x.flow = e[i + 1].cap;
			a.push_back(x);
		}
		return a;
	}
	void print(int s, int t){
		// auto p = edges();
		// for(auto [f, t, c, fl] : p) {
		// 	std::cout << f << " " << t << " " << c << " " << fl << "\n";
		// }

		for (int i = 0; i < e.size(); i += 2) {
			int u = e[i + 1].to;
			int v = e[i].to;
			if(u != s && v != t && e[i + 1].cap) {
				std::cout << u << " " << v << "\n";
			}
		}
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;
	int a, b;
	Flow<int> f(n + m + 2);

	while(std::cin >> a >> b && !(a == -1 || b == -1)) {
		f.add(a, b, 1);
	}
	for(int i  = 1; i <= n; i++) f.add(0, i, 1);
	for(int i  = n + 1; i <= m; i++) f.add(i, m + n + 1, 1);
	
	int ans = f.flow(0, m + 1 + n);
	std::cout << ans << "\n";
	f.print(0, m + 1 + n);
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