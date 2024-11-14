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
	int a, b, c;
	std::cin >> a >> b;
	std::cin >> c;
	a += c;
	std::cin >> c;
	b += c;
	std::string l = std::to_string(a), r = std::to_string(b);
	while(l.size() < r.size()) l = '0' + l;
	// std::cout << l << ' ' << r << "\n";
	std::vector dp(30, std::vector<int>(300, -1));
	auto dfs = [&](auto &&self, int i, int is_limitl, int is_limitr, int is_num, i64 num) -> i64 {
		if(i == r.size()){
			return num;
		}
		if(!is_limitl && !is_limitr && dp[i][num] != -1) return dp[i][num];
		i64 res = 0;
		if(!is_num) res = std::max(res, self(self, i + 1, is_limitl, is_limitl, is_num, num));
		for(int d = (is_limitl ? l[i] - '0' : 9), u = (is_limitr ? r[i] - '0' : 9); d <= u; d++){
			res = std::max(res, self(self, i + 1, is_limitl && (d == l[i] - '0'), is_limitr && (d == r[i] - '0'), 1, num + d));
		}
		if(!is_num && !is_limitl && !is_limitr) dp[i][num] = res;
		return res;
	};
	std::cout << dfs(dfs, 0, 1, 1, 1, 0) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}