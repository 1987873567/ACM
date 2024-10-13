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
	std::string s;
	std::cin >> s;

	for(int i = 0; i < n; i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			std::cout << "shameimaru\n";
			return;
		}
	}
	std::vector<int> v(26);
	for(int i = 0; i < n; i++){
		if(v[s[i] - 'a']){
			std::cout << "shameimaru\n";
			return;
		}
		v[s[i] - 'a'] = 1;
		if(((n - i - 1) & 1) || (n - i - 1) < 2)continue;
		int len = (n - i - 1) / 2;
		if(s.substr(i + 1, len) == s.substr(i + len + 1)){
			std::cout << "aya\n";
			return;
		}
		// std::cerr <<  << " " <<  << "\n";
	}
	std::cout << "shameimaru\n";

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