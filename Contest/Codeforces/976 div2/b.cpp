#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
//求sqrt
i64 Sqrt(i64 x){
	i64 t = std::sqrt(x)+0.5;
	while(t*t>x)t--;
	return t;
}


void db(){
	int n = 1000;
	std::vector<int> v(1001, 1);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			v[j] ^= 1;
		}
	}
	for(int i = 1; i <= 100; i++){
		std::cout << i << " " << v[i] << "\n";
	}
}
void solve() {
	// db();
	i64 n;
	std::cin >> n;
	i64 l = 0, r = 2e18;
	auto f = [&](i64 x)-> i64{
		i64 t = Sqrt(x);
		i64 res = x - t;
		return res;
	};
	while(l + 1 != r){
		i64 m = (l + r) >> 1;
		if(f(m) < n){
			l = m;
		}else {
			r = m;
		}
	}
	std::cout << r << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));
    // db();
    int _ = 1;
    // std::cout << (int)std::sqrt(1e18) << "\n";
    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}