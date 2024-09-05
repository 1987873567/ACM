#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
#define int long long
#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(a) a.begin(), a.end()
#define CF cout.flush();
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 1e6;
constexpr int mod = 1e9 + 7;
constexpr ld eps = 1e-6;

struct DSU {
    std::vector<int> f, cnt;
    DSU(int n) {
        f.resize(n + 1);
        cnt.resize(n + 1);
        iota(all(f), 0);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    void add(int x, int y) {
        x = find(x), y = find(y);
        // if (x > y) swap(x, y);
        if (x != y) {
            f[y] = x;
            cnt[x] += cnt[y];
        }
    }
    bool s(int x, int y) { return find(x) == find(y); }
    int c(int x) { return cnt[find(x)]; }
};



void solve() {
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	std::vector<std::vector<int>> g(n);
	std::map<int,int> c;
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
		if (!c.count(v[i])) {
			c[v[i]] = c.size();
		}
		assert(c[v[i]] < n);
		g[c[v[i]]].push_back(i);
	}
	
	int m = 0;
	std::cin >> m;

	while (m--) {
		std::string s;
		std::cin >> s;
		int flag = 1;

		if(s.size() != n) flag = 0;
		else {
			std::vector<std::vector<int>> g2(n);
			std::map<int,int> c1;
			for (int i = 0; i < n; i++) {
				if (!c1.count(s[i])) {
					c1[s[i]] = c1.size();
				}
				g2[c1[s[i]]].push_back(i);
			}
			flag = (g2 == g);
		}
		if (flag) {
			YES;
		} else {
			NO;
		}
	}
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}