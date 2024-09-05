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
	std::string s;
	std::cin >> n >> s;
	i64 res = 0;
	std::map<char,int> vis;
	std::vector<int> suf(n + 1);
	for (int i = n - 1; i >= 0; i--){
		if (!vis[s[i]]) {
			vis[s[i]] =	1;
			suf[i] = suf[i + 1] + 1;
			res++;
		} else {
			suf[i] = suf[i + 1];
		}
	}
	vis.clear();
	for (int i = 0; i < n; i++){
		if(!vis[s[i]]){
			res += suf[i + 1];
			vis[s[i]] = 1;
		}
	}
	std::cout << res << "\n"; 
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