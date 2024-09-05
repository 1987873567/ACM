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

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> v(n + 1), sum(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
		sum[i] += sum[i - 1] + v[i];
	}
	std::string s;
	std::cin >> s;
	std::queue<int> l;
	std::stack<int> r;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == 'L') l.push(i);
		else r.push(i);
	}
	while(l.size() && r.size()) {
		int x = l.front();
		l.pop();
		while(r.size() && r.top() < x) r.pop();
		if (r.size()) {
			int y = r.top();
			r.pop();
			ans += sum[y + 1] - sum[x];
		}
	}
	std::cout << ans << "\n";
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