#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
i64 p[22] = {1};
void solve() {
	int n;
	std::cin >> n;

	for(int i = 1; i <= 20; i++){
		p[i] = p[i - 1] * 3;
		// std::cout << p[i] << "\n";
	}
	std::vector<int> ans;
	while(n){
		for(int i = 20; i >= 0; i--){
			if(n >= p[i]){
				n -= p[i];
				ans.push_back(i);
				break;
			}
		}
	}
	std::cout << ans.size() << "\n";
	for(auto i : ans){
		std::cout << i << " ";
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