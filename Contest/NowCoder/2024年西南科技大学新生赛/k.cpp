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
	std::set<int> a;
	for(int i = 0, x; i < n; i++){
		std::cin >> x;
		a.insert(x);
	}
	std::set<int> vis;
	for(int i = 0, x; i < n; i++){
		std::cin >> x;
		if(a.count(x)){
			vis.insert(x);
		}
	}
	std::cout << vis.size() << '\n';
	std::vector<int> ans(all(vis));
	for(int i = 0; i < ans.size(); i++){
		std::cout << ans[i] << " \n"[i == ans.size() - 1];
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