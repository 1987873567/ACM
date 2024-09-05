#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> r(n + 1), ans;
	std::vector<std::vector<int>> g(n + 1);

	// std::vector<int> min(n + 1);
	// std::iota(min.begin(), min.end(), 0);

	for(int i = 0; i < m; i++){
		int a, b;
		std::cin >> a >> b;
		r[a]++;
		g[b].push_back(a);
		// min[a] = std::min(min[a], min[b]);
	}

	
	// using pii = std::pair<int, int>;
	// auto cmp = [&](const int &x,const int &y) {
	// 	if(min[x] == min[y]) return x > y;
	// 	return min[x] > min[y];
	// };

	// std::priority_queue<int,std::vector<int>,decltype(cmp)> q(cmp);
	std::priority_queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		if(!r[i])q.push(i);
	}
	while (q.size()) {
		int x = q.top();
		q.pop();
		ans.push_back(x);
		for(auto i : g[x]){
			if(--r[i] == 0) {
				q.push(i);
			}
		}
	}
	if(ans.size() != n) {
		std::cout << "Impossible!\n";
	}else{
		for(int i = n - 1; i >= 0; i--) {
			std::cout << ans[i] << " \n"[i == 0];
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
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}