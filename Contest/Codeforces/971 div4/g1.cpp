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
	int n, k, q;
	std::cin >> n >> k >> q;
	std::vector<int> v(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
		v[i] -= i;
	}

	std::vector<int> max(n + 1);
	std::map<int, int> cnt, w;

	for (int i = 1; i <= n; i++) {
		if(cnt.count(w[v[i]])){
			cnt[w[v[i]]]--;
			if(!cnt[w[v[i]]]) cnt.erase(w[v[i]]);
		}
		w[v[i]]++;
		cnt[w[v[i]]]++;
		if(i < k) continue;
		max[i - k + 1] = cnt.rbegin() -> first; 
		cnt[w[v[i - k + 1]]]--;
		if(!cnt[w[v[i - k + 1]]]) cnt.erase(w[v[i - k + 1]]);
		w[v[i - k + 1]]--;
		if(w[v[i - k + 1]]) cnt[w[v[i - k + 1]]]++;
	}
	
	while(q--){
		int l, r;
		std::cin >> l >> r;
		std::cout << k - max[l] << "\n";
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