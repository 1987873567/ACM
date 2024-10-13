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
	int n, q;
	std::cin >> n >> q;
	std::string s;
	std::cin >> s;
	int ans = 0;
	for(int i = 0; i < n - 2; i++){
		if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
			ans++;
		}
	}
	while(q--){
		int p;
		char c;
		std::cin >> p >> c;
		p--;
		for(int i = std::max(0, p - 2); i <= std::min(n - 1, p + 2); i++){
			if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
				ans--;
			}
		}
		s[p] = c;
		for(int i = std::max(0, p - 2); i <= std::min(n - 1, p + 2); i++){
			if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
				ans++;
			}
		}
		std::cout << ans << "\n";
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