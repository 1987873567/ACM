#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 2e5;

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	s = ' ' + s;
	std::vector<std::array<int, 26>> sum1(n + 1),sum2(n + 1);
	for(int i = 1; i <= n; i++){
		sum1[i] = sum1[i - 1];
		sum2[i] = sum2[i - 1];
		if(i & 1) {
			sum1[i][s[i] - 'a']++;
		} else {
			sum2[i][s[i] - 'a']++;
		}
		
	}
	int ans = 1e9;
	if(n & 1){
		for(int i = 1; i <= n; i++){
			int a = 0, b = 0;
			for(int j = 0; j < 26; j++){
				a = std::max(a, sum1[i - 1][j] + sum2[n][j] - sum2[i][j]);
				b = std::max(b, sum2[i - 1][j] + sum1[n][j] - sum1[i][j]);
			}
			ans = std::min(ans, n - a - b);
		}
	} else {
		ans = n - *std::max_element(all(sum1[n])) - *std::max_element(all(sum2[n]));
	}
	std::cout << ans << "\n";
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