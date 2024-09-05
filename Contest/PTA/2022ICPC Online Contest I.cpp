#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	std::string s, t;
	std::cin >> s >> t;
	int n = s.size(), m = t.size();
	//最后一个在t中的字符
	std::vector<std::array<int, 26>> dp(n + 1) , nex(26);
	std::vector<int> vis(26);

	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			if(vis[j]) nex[t[i] - 'a'][j] = 1;
		}
		vis[t[i] - 'a'] = 1;
	}

	for (int i = 1; i <= n; i++) {
		int a = s[i - 1] - 'a';
		for(int j = 0; j < 26; j++) {
			dp[i][j] = dp[i - 1][j] + (!vis[a]);
		}
		for(int j = 0; j < 26; j++) {
			if(!nex[j][a] && vis[a]) {
				dp[i][a] = std::max(dp[i][a], dp[i - 1][j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		ans = std::max(ans, dp[n][i]);
	}
	std::cout << ans << '\n';
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