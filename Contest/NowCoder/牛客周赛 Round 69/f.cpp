#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
template <typename T>
struct bt {
    int n;
    std::vector<T> a;
    bt(){init(0);}
    bt(int n){init(n);}
    void init(int n){
    	this->n = n + 1;
    	a.assign(n + 1, 0);
    }
    void add(int i, T v) {
        for (; i <= n; i += i & -i) {
            a[i] += v;
        }
    }
    T ask(int i) {
        T ans = 0;
        for (; i; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    T ask(int l, int r) { return ask(r) - ask(l - 1); }
};

struct red{
	bt<i64> r, e, d, re, ed;
	int n;
	red(const std::string s){
		this->n = s.size();
		r.init(n);
		e.init(n);
		d.init(n);
		re.init(n);
		ed.init(n);
	}
	void init(const std::string &s){
		for(int i = 1; i <= n; i++){
			r.add(i, s[i] == 'r');
			e.add(i, s[i] == 'e');
			d.add(i, s[i] == 'd');
		}
		for(int i = 1; i <= n; i++){
			re.add(i, (s[i] == 'e') * r.ask(i));
			ed.add(i, (s[i] == 'e') * d.ask(i, n));
		}
	}
	void add()
};


void solve() {
	int n, q;
	std::cin >> n >> q;
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