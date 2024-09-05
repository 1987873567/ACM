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
	int t = std::sqrt(n);
	if (t * t == n) {
		int flag = 1;
		for(int i = 0; i < t; i++){
			flag &= (s[i] == '1');
			flag &= (s[(t - 1) * t + i] == '1');
		}
		for(int i = 1; i < t - 1; i++){
			flag &= (s[i * t] == '1');
			for(int j = 1; j < t - 1; j++){
				flag &= (s[i * t + j] == '0');
			}
			flag &= (s[i * t + t - 1] == '1');
		}
		if(flag){
			YES;
		} else {
			NO;
		}
	} else {
		NO;
	}
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