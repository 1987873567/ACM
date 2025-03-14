#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()
#define int long long
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d4[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
// constexpr int d8[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n + 1), sum(n + 1);
    for(int i = 1; i <= n; i++){
    	std::cin >> v[i];
    	sum[i] = sum[i - 1] + (v[i] == 0);
    }
    std::set<int> vis;
    std::vector<int> suf(n + 1);
    for(int i = n; i >= 1; i--){
    	suf[i] = vis.size();
    	if(v[i]){
    		vis.insert(v[i]);
    	}
    }
    std::vector<std::vector<int>> g(1e6 + 1);
    for(int i = 1; i <= n; i++){
    	if(!v[i]) continue;
    	g[v[i]].push_back(i);
    }
    int ans = 0;
    for(auto &a : g){
    	if(a.size() < 2) continue;
    	int l = 0, r = a.size() - 1;
    	while(l + 1 != r){
    		int m = (l + r) / 2;
    		if(sum[a[m]] - sum[a[0]]){
    			r = m;
    		} else {
    			l = m;
    		}
    	}

    	if(sum[a[r]] - sum[a[0]]) ans += suf[a[r]];
    }
    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}