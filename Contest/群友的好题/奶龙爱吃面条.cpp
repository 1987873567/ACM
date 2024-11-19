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
	int n, m;
	std::cin >> n >> m;
	using pii = std::pair<i64,int>;
	std::priority_queue<pii, std::vector<pii>,std::greater<>> out;
	std::priority_queue<int, std::vector<int>,std::greater<>> in;
	std::vector<i64> ans(n + 1);
	for(int i = 1; i <= n; i++) in.push(i);
	for(int i = 0; i < m; i++){
		i64 t, w, s;
		std::cin >> t >> w >> s;
		while(out.size() && out.top().first <= t) 
			in.push(out.top().second), out.pop();
		if(in.size()){
			int p = in.top();
			in.pop();
			ans[p] += w;
			out.push({t + s, p});
		}
	}
	for(int i = 1; i <= n; i++){
		std::cout << ans[i] << "\n";
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