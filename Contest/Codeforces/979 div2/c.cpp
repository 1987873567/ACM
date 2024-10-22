#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
/*
1 or 0 and 1 and 0 or 1
0 or 0 and 0 or 1 and 0 or 1 and 1
*/
	int n;
	std::cin >> n;
	int ans = 0, sum = 0;
	std::string s;
	std::cin >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			sum++;
		}else{
			ans = std::max(sum, ans);
			sum = 0;
		}
	}
	ans = std::max(sum, ans);
	if(ans >= 2 || s[0] == '1' || s.back() == '1'){
		YES;
	}else{
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