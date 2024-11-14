#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

template<class T, class Cmp = std::less<T>>
struct RMQ {
    const Cmp cmp = Cmp();
    static constexpr unsigned B = 64;
    using u64 = unsigned long long;
    int n;
    std::vector<std::vector<T>> a;
    std::vector<T> pre, suf, ini;
    std::vector<u64> stk;
    RMQ() {}
    RMQ(const std::vector<T> &v) {
        init(v);
    }
    void init(const std::vector<T> &v) {
        n = v.size();
        pre = suf = ini = v;
        stk.resize(n);
        if (!n) {
            return;
        }
        const int M = (n - 1) / B + 1;
        const int lg = std::__lg(M);
        a.assign(lg + 1, std::vector<T>(M));
        for (int i = 0; i < M; i++) {
            a[0][i] = v[i * B];
            for (int j = 1; j < B && i * B + j < n; j++) {
                a[0][i] = std::min(a[0][i], v[i * B + j], cmp);
            }
        }
        for (int i = 1; i < n; i++) {
            if (i % B) {
                pre[i] = std::min(pre[i], pre[i - 1], cmp);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (i % B != B - 1) {
                suf[i] = std::min(suf[i], suf[i + 1], cmp);
            }
        }
        for (int j = 0; j < lg; j++) {
            for (int i = 0; i + (2 << j) <= M; i++) {
                a[j + 1][i] = std::min(a[j][i], a[j][i + (1 << j)], cmp);
            }
        }
        for (int i = 0; i < M; i++) {
            const int l = i * B;
            const int r = std::min(1U * n, l + B);
            u64 s = 0;
            for (int j = l; j < r; j++) {
                while (s && cmp(v[j], v[std::__lg(s) + l])) {
                    s ^= 1ULL << std::__lg(s);
                }
                s |= 1ULL << (j - l);
                stk[j] = s;
            }
        }
    }
    //区间左闭右开
    T operator()(int l, int r) {
        if (l / B != (r - 1) / B) {
            T ans = std::min(suf[l], pre[r - 1], cmp);
            l = l / B + 1;
            r = r / B;
            if (l < r) {
                int k = std::__lg(r - l);
                ans = std::min({ans, a[k][l], a[k][r - (1 << k)]}, cmp);
            }
            return ans;
        } else {
            int x = B * (l / B);
            return ini[__builtin_ctzll(stk[r - 1] >> (l - x)) + l];
        }
    }
};
void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<std::pair<int, int>>> g(n + 1);
	std::vector<i64> sum(n + 1), l(n + 1), r(n + 1), deep(n + 1);
	std::vector<std::vector<i64>> p(n + 1), val(n + 1);
	std::vector<RMQ<i64, std::greater<>>> rmq(n + 1);
	for(int i = 1; i < n; i++){
		int a, b, c;
		std::cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	int tot = 0;
	auto dfs = [&](auto &&self, int x, int f) -> void{
		l[x] = ++tot;
		deep[x] = deep[f] + 1;
		p[deep[x]].push_back(tot);
		val[deep[x]].push_back(sum[x]);
		for(auto [y, w] : g[x]){
			if(y ^ f){
				sum[y] += sum[x] + w;
				self(self, y, x);
			}
		}
		r[x] = ++tot;
	};
	dfs(dfs, 1, 1);

	for(int i = 1; i <= n; i++){
		rmq[i].init(val[i]);
	}

	int q;
	std::cin >> q;
	while(q--){
		int x, dis;
		std::cin >> x >> dis;
		if(deep[x] + dis > n){
			std::cout << "-1\n";
			continue;
		}
		auto &v = p[deep[x] + dis];
		auto il = std::lower_bound(all(v), l[x]);
		auto ir = std::upper_bound(all(v), r[x]);

		if(il == v.end() || ir == v.begin() || ir == il){
			std::cout << "-1\n";
			continue;
		}
		ir = std::prev(ir);
		int L = il - v.begin(), R = ir - v.begin() + 1;
		std::cout << rmq[deep[x] + dis](L, R) - sum[x] << "\n";
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