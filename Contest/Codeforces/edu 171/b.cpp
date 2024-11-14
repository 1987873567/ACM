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
	std::vector<i64> b(n);
	for(int i = 0; i < n; i++){
		std::cin >> b[i];
	}
	auto f = [&](i64 x){
		int flag = 0;
		for(int i = 1; i < n; i += 2){
			if(b[i] - b[i - 1] > x){
				flag++;
				i = i + 1;
				i -= 2;
			}
		}
		return flag <= (n & 1);
	};

	i64 l = 0, r = 1e18;
	while(l + 1 != r){
		i64 m = (l + r) >> 1;
		if(f(m)){
			r = m;
		} else {
			l = m;
		}
	}
	std::cout << r << "\n";
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