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
	std::string s, t;
	std::cin >> s >> t;
	int n = s.size();
	std::vector<std::string> ans;
	std::priority_queue<std::array<int, 2>> q;
	for(int i = 0; i < n; i++){
		if (s[i] > t[i]) {
			s[i] = t[i];
			ans.push_back(s);
		}
	}
	for(int i = n - 1; i >= 0; i--){
		if (s[i] != t[i]) {
			s[i] = t[i];
			ans.push_back(s);
		}
	}
	std::cout << ans.size() << '\n';
	for(auto i : ans) {
		std::cout << i << '\n';
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