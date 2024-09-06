#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 2e5;

int p[N + 1];

void solve() {
	int n;
	std::cin >> n;
	__gnu_pbds::gp_hash_table<int, int> cnt;
	for(int i = 0, x; i < n; i++){
		std::cin >> x;
		cnt[x]++;
	}
	int m;
	std::cin >> m;
	int c1 = 0,c2 = 0, id = 1;
	for(int i = 1, a; i <= m; i++){
		std::cin >> a;
		if(cnt[a] > c1) id = i, c1 = cnt[a];
		p[i] = a;
	}
	for(int i = 1, a; i <= m; i++){
		std::cin >> a;
		if (cnt[p[i]] == c1) {
			if(cnt[a] > c2) c2 = cnt[a], id = i;
		}
	} 
	std::cout << id << "\n";
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