#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve1() {
	i64 n;
	std::cin >> n;
	std::priority_queue<i64> q;
	i64 ans = 0;
	for(int i = 0, x; i < n; i++){
		std::cin >> x;
		q.push(x);
		if(q.top() > x){
			ans += q.top() - x;
			q.pop();
			q.push(x);
		}
	}
	std::cout << ans << "\n";
}

i64 dp[2][5500], v[5500], a[5500];

void solve() {
	memset(dp, 0x3f3f, sizeof dp);
	i64 n;
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
		a[i] = v[i];
		dp[0][i] = 0; 
	}
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[1][j] = std::min(dp[1][j - 1], dp[0][j] + std::abs(v[i] - a[j])); 
		}
		std::swap(dp[0], dp[1]);
	}
	i64 ans = 1e18;
	for(int i = 1; i <= n; i++){
		ans = std::min(dp[0][i], ans);
	}
	std::cout << ans << "\n";
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