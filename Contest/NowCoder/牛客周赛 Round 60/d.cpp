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
	i64 n;
	std::cin >> n;
	std::vector<i64> v(n);
	
	for(i64 i = 0; i < n; i++){
		std::cin >> v[i];
	}
	
	std::sort(all(v));
	i64 sum = 1;
	
	for(i64 i = 0; i < n; i++){
		if(v[i] > sum) break;
		sum += v[i];
	}

	if(sum > n){
		std::cout << "Cool!\n";
	} else {
		std::cout << sum << "\n";
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