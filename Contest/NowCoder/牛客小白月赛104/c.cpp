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
	std::vector<int> v(n);
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}
	auto f = [&](i64 x){
		i64 a, b;
		a = b = x;
		auto vv = v;
		int cnt = 0;
		for(i64 i = 0; i < n; i++){
			vv[i] -= x;
			vv[i] = std::max(vv[i], 0); 
			if(vv[i] <= 0)cnt++;
		}
		for(i64 i = 0; i < n - 1; i++){
			if(vv[i] && vv[i + 1]){
				i64 t = std::min({vv[i], vv[i + 1], (int)a});
				a -= t;
				vv[i] -= t;
				vv[i + 1] -= t;
				cnt += (!vv[i]) + (!vv[i + 1]);
			}
		}
		b += a;
		for(i64 i = 0; i < n; i++){
			if(vv[i]){
				i64 t = std::min({vv[i], (int)b});
				b -= t;
				vv[i] -= t;
				cnt += (!vv[i]);
			}
		}
		return cnt == n;
	};

	i64 l = 0, r = 1e9 + 1;
	while(l + 1 != r){
		i64 m = (l + r) >> 1;
		if(f(m)){
			r = m;
		} else {
			l = m;
		}
	}
	for(int i = l - 10; i <= r + 10; i++){
		if(i >= 0 && f(i)){
			std::cout << i << "\n";
			return;
		}
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