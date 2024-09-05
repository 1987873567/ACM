#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int flag = 1;
std::vector<i64> get(i64 n, i64 k){
	std::vector<i64> s;
	while(n){
		if(n % k > 1)flag = 0;
		s.push_back(n % k);
		n /= k;
	}
	// std::reverse(all(s));
	return s;
}
i64 db(i64 n, i64 k) {
    i64 ans = 1;
	for (i64 i = 1; i * i<= n; i++){
		if(n % i == 0){
			flag = 1;
			auto s = get(i, k);
			std::cerr << "i:" << i <<"\n";
			for(int j : s){
				std::cerr << j << ' ';
			}
			std::cerr << "\n";
			if(flag){
				
				ans = std::max(ans ,i);
			}
            flag = 1;
            std::cerr << "i:" << n / i <<"\n";
            auto ss = get(n / i, k);
            for(int j : ss){
				std::cerr << j << ' ';
			}
			std::cerr << "\n";
            }
            if(flag){
                ans = std::max(ans ,n / i);
				
		}
	}
	return ans;
}
void solve() {
	i64 n, k;
	std::cin >> n >> k;
	std::vector<i64> s = get(n, k);
	std::cout << n / db(n, k) << "\n";
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
    // system("pause");
    return 0;
}