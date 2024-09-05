#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
template <typename T>
struct S_2D {
    using v2 = std::vector<std::vector<T>>;
    using v1 = std::vector<T>;
    v2 v;
    int n, m;
    S_2D(int n = 0, int m = 0) : n(n), m(m) {v.resize(n+2,v1(m+2));}
    S_2D(const v2 &t, int n ,int m) : n(n), m(m), v(t) {}
    void add(int r1, int l1, int r2, int l2, int val) {
        v[r1][l1] += val, v[r2 + 1][l2 + 1] += val, v[r2 + 1][l1] -= val, v[r1][l2 + 1] -= val;
    }
    void S() {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
    }
    void print() {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) std::cout << v[i][j] << " \n"[j == m];
    }
    int ask(int r1, int l1, int r2, int l2) { return v[r2][l2] - v[r2][l1 - 1] - v[r1 - 1][l2] + v[r1 - 1][l1 - 1]; }
};
void solve() {
	int n;
	std::cin >> n;
	S_2D<i64> **d2 = new S_2D<i64>*[n + 1];
	std::vector<std::vector<i64>> v(n + 1, std::vector<i64> (n + 1));
	for (int z = 1; z <= n; z++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				std::cin >> v[i][j];
			}
		}
		d2[z] = new S_2D<i64>(v, n, n);
		d2[z]->S();
	}
	int q;
	std::cin >> q;
	while (q--) {
		int xl, xr, yl, yr, zl, zr;
		std::cin >> zl >> zr >> xl >> xr >> yl >> yr;
		i64 ans = 0;
		int x1 = xl, y1 = yl, x2 = xr, y2 = yr; 
		for (int z = zl; z <= zr; z++) {
			ans += d2[z]->ask(x1, y1, x2, y2);
		}
		std::cout << ans << '\n';
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}