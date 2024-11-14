#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int f(int a, int b){
	int i = b;
	while(i >= 2){
		if(a % i == 0){
			return a / i;
		}
		i--;
	}
	return a;
}
void solve() {
	// int n ;
	// std::cin >> n;
	// int ans = 0;
	// for(int i = 1; i <= n; i++){
	// 	int t = f(n, i);
	// 	ans += t;
	// 	// std::cout << t << " " << i << '\n';
	// }
	// std::cout << ans << "\n";
	i64 n;
	std::cin >> n;
	i64 ans = 0;
	std::vector<i64> y;
	for(i64 i = 1; i * i <= n; i++){
		if(n % i == 0){
			y.push_back(i);
			if(i * i != n){
				y.push_back(n / i);
			}
		}
	}
	std::sort(all(y));
	for(i64 i = 1; i < y.size(); i++){
		ans += (y[i] - y[i - 1]) * (n / y[i - 1]);
	}
	std::cout << ans + 1 << "\n";
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