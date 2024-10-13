#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr i64 mod = 998244353;

template <typename T>
struct BTree {
    const int n;
    std::vector<T> a;
    BTree(int n) : n(n + 10), a(n + 10) {}
    void add(int i, T v) {
        for (; i <= n; i += i & -i) {
            a[i] += v;
            a[i] %= mod;
        }
    }
    T ask(int i) {
        T ans = 0;
        for (; i; i -= i & -i) {
            ans += a[i];
            ans %= mod;
        }
        return ans;
    }
    T ask(int l, int r) { return (ask(r) - ask(l) + mod) % mod; }
};
i64 p[1010100] = {1};


void solve() {
	std::string s;
	int n, q;
	std::cin >> n >> q >> s;
	for(int i = 1; i <= n; i++){
		p[i] = (p[i - 1] * 27) % mod;
	}
	s = ' ' + s;
	BTree<i64> pre(n + 1), suf(n + 1);
	for(int i = 1; i <= n; i++){
		pre.add(i,(p[i - 1] * (s[i] - 'a' + 1)) % mod);
		suf.add(n - i + 1, (p[n - i] * (s[i] - 'a' + 1)) % mod);
	}
	auto hs = [&] (i64 l, i64 r, auto &x) {
		return (x.ask(r) - x.ask(l - 1) + mod) % mod * p[n - l] % mod; 
	};
	while(q--){
		i64 op, l, r;
		char c;
		std::cin >> op >> l;
		if(op == 1) {
			std::cin >> c;
			pre.add(l, p[l - 1] * (c - s[l] + mod) % mod);
			suf.add(n - l + 1, p[n - l] * (c - s[l] + mod) % mod);
			s[l] = c;
		} else {
			std::cin >> r;
			if(hs(l, r, pre) == hs(n- r + 1,n - l + 1, suf)) YES;
			else NO;
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