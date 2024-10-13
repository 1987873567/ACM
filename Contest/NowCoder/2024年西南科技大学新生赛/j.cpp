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
	int n, h;
	std::cin >> n >> h;
	std::vector<int> v(n), id(n), ans;
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
		id[i] = i;
	}
	std::sort(all(id), [&](int x, int y){
		if(v[x] == v[y]){
			return x < y;
		}
		return v[x] > v[y];
	});
	// for(auto i : id){
	// 	std::cout << i << " ";
	// }
	for(int i = 0; i < n && h > 0; i++){
		ans.push_back(id[i] + 1);
		h -= v[id[i]];
	}
	if(h > 0){
		NO;
	}else{
		YES;
		std::cout << ans.size() << '\n';
		for(auto i : ans){
			std::cout << i << " ";
		}
		std::cout << "\n";
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