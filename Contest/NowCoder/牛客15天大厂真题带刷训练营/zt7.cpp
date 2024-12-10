#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
bool ask(int x){
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) return 1;
	}
	return 0;
}
void solve() {
	int n;
	std::cin >> n;
	std::vector<int> v(n + 1);
	std::iota(all(v), 0);
	int flag = 0;
	for(int i = 1; i <= n; i++){
		if(ask(1 + i)){
			std::swap(v[1], v[i]);
			flag = 1;
			break;
		}
	}
	if(flag){
		for(int i = 1; i <= n; i++){
			std::cout << v[i] << " \n"[i == n];
		}
	} else {
		std::cout << "-1\n";
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