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
	int n;
	std::cin >> n;
	std::string mp[2];
	for(int i = 0; i < 2; i++)std::cin >> mp[i];
	std::vector<std::vector<int>> dp(2 , std::vector<int> (n + 1, - 1e9));
	int ans = 0;
	dp[0][0] = 0;
	auto fun = [&](char x, char y, char z){
		return ((x == 'A') + (y == 'A') + (z == 'A')) >= 2;
	};
	for(int i = 0; i < n; i++){
		 if(i % 3 == 0){
		 	dp[0][i + 3] = std::max(dp[0][i + 3], dp[0][i] + fun(mp[0][i], mp[0][i + 1], mp[0][i + 2]) + fun(mp[1][i], mp[1][i + 1], mp[1][i + 2]));
		 	dp[0][i + 1] = std::max(dp[0][i + 1], dp[0][i] + fun(mp[0][i], mp[0][i + 1], mp[1][i]));
		 	dp[1][i + 1] = std::max(dp[1][i + 1], dp[0][i] + fun(mp[0][i], mp[1][i], mp[1][i + 1])); 
		 }else if(i % 3 == 1){
		 	if(i + 3 < n){
		 		dp[0][i + 3] = std::max(dp[0][i + 3], dp[0][i] + fun(mp[0][i + 1], mp[0][i + 2], mp[0][i + 3]) + fun(mp[1][i], mp[1][i + 1], mp[1][i + 2]));
		 		dp[1][i + 3] = std::max(dp[1][i + 3], dp[1][i] + fun(mp[0][i], mp[0][i + 1], mp[0][i + 2]) + fun(mp[1][i + 1], mp[1][i + 2], mp[1][i + 3]));
		 	}
		 	dp[0][i + 2] = std::max(dp[0][i + 2], dp[0][i] + fun(mp[0][i + 1], mp[1][i + 1], mp[1][i]));
		 	dp[0][i + 2] = std::max(dp[0][i + 2], dp[1][i] + fun(mp[0][i + 1], mp[1][i + 1], mp[0][i]));
		 }
	}
	std::cout << dp[0][n] << '\n';

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