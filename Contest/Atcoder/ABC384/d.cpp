#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()
#define int long long
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n, s;
	std::cin >> n >> s;
	int sum = 0;
	std::vector<int> v(n * 2);
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
		v[i + n] = v[i];
		sum += v[i];
	}
	assert(sum);
	s %= sum;
	if(s == 0){
		YES;
		return;
	}
	// std::cout << s << "\n";
	std::map<int, int> S;
	S[0] = 1;
	int flag = 0;
	for(int i = 0, ss = 0; i < n * 2; i++){
		ss += v[i];
		if(S.count(ss - s)){
			flag = 1;
		}
		S[ss] = 1;
	}
	if(flag){
		YES;
	} else {
		NO;
	}
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}