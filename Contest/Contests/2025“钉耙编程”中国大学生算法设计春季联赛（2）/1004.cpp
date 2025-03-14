#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d4[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
// constexpr int d8[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

void solve() {
    std::string s, kk;
    std::cin >> s >> kk;
    int k;
    if(kk.size() >= 3) k = 50;
    else k = std::stoi(kk);
    std::string ts = "";
    while(k){
    	ts += s;
    	k--;
    }
    int ans = 0;
	std::vector<int> dp(ts.size(), 1);
	for(int i = 0; i < ts.size(); i++){
		for(int j = 0; j < i; j++){
			if(ts[j] < ts[i]) dp[i] = std::max(dp[i], dp[j] + 1);
		}
		ans = std::max(ans, dp[i]);
	}
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}