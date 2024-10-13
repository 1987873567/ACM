#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	i64 s, n, k;
	std::cin >> s >> n >> k;
	std::vector<i64> v(n + 10);
	if(k > n) {
		NO;
		return;
	}
	for(i64 i = 0; i < k; i++){
		v[i] = i;
		s -= i;
	}
	if (k == 0) {
		if(s >= n) {
			YES;
			for(i64 i = 0 ; i < n - 1; i++){
				std::cout << "1 ";
			}
			std::cout << s - n + 1 << '\n';
		}else{
			NO;
		}
		return;
	}
	if(s < 0) {
		NO;
	} else {
		if((n - k == 1 && s == k) || (n == k && s)){
			NO;
		} else {
			if (s == k) {
				if(s == 1) {
					NO;
					return;
				}
				v[k] = k - 1;
				v[k + 1] = 1;
			} else {
				v[k] = s;
			}
			YES;
			for(i64 i = 0; i < n; i++){
				std::cout << v[i] << " \n"[i == n - 1];
			}
		}

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