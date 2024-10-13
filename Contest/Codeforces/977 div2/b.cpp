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
	int n, x;
	std::cin >> n >> x;
	std::map<i64, int> c;
	std::set<int> mex;

	for(int i = 0; i <= n + 2; i++){
		mex.insert(i);
	}

	for(int i = 0, y; i < n; i++){
		std::cin >> y;
		c[y]++;
	}
	for(auto [i, cc] : c){
		if(i > n + 1)continue;
		if(*mex.begin() < i)break;
		i64 y = *mex.lower_bound(i);
		y = (y - i) / x * x + i;
		while(cc && y <= n + 1){
			if(mex.count(y)){
				cc--;
				mex.erase(y);
			}
			y += x;
		}
	}
	std::cout << *mex.begin() << "\n";
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