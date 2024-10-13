#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
void db(){
	int n = 1;
	std::cin >> n;
	std::vector<int> v(n);
	std::iota(all(v),1);
	int k = 1;
	std::vector<std::set<int>> ans(n * (n - 1) / 2 + 1);
	do{
		int p = 0, q = 0;
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				if(v[i] > v[j]) p++;
				if(v[i] < v[j]) q++;
			}
		}
		ans[p] .insert(q);
	}while(std::next_permutation(all(v)));
	int c = 0;
	for(auto i : ans) {
		// std::cout<<"k:" << c++ << "\n";
		// if(i.size() <= 1) continue;
		for(auto j : i) {
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
}
void solve() {
	// db();
	i64 n, k;
	std::cin >> n >> k;
	i64 ans = (n * (n - 1) / 2) - k;
	// if(n == 1) {
	// 	ans = 0;
	// }
	std::cout << ans << '\n';
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