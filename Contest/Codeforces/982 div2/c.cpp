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
	i64 n;
	std::cin >> n;
	std::vector<i64> v(n + 1);
	std::map<i64, std::vector<i64>> pos;
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
		v[i] += (i - 1);
		pos[v[i]].push_back(i);
	}
	std::priority_queue<std::pair<i64,i64>> q;
	std::unordered_map <i64, i64> vis;

	q.push({n, 1});
	i64 ans = n;
	vis[1] = n;

	while(q.size()){
		auto [len, id] = q.top();
		q.pop();
		ans = std::max(ans, len);
		for(auto &i : pos[len]){
			if(vis.count(i)){
				if(vis[i] < vis[id] + i - 1){
					vis[i] = vis[id] + i - 1;
					q.push({vis[i], i});
				}
			} else {
				vis[i] = vis[id] + i - 1;
				q.push({vis[i], i});
			}
		}
	}
	std::cout << ans << "\n";
	//
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