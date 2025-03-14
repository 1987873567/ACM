#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d4[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
// constexpr int d8[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n + 1), c(n + 1);
    std::vector<i64> ans(m + 1);
    std::priority_queue<std::array<i64, 2>, std::vector<std::array<i64, 2>>, std::greater<>> q;
    for(int i = 1; i <= n; i++){
    	std::cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
    	std::cin >> c[i];
    	q.push({c[i], i});
    }
    for(int i = 1; i <= m; i++){
    	i64 t, d;
    	std::cin >> t >> d;
    	i64 x = t;
    	i64 cd = std::min(d, a[x]);
		d -= cd;
		a[x] -= cd;
		ans[i] += cd * c[x];
    	while(d && q.size()){
    		x = q.top()[1];
    		q.pop();
    		cd = std::min(d, a[x]);
    		d -= cd;
    		a[x] -= cd;
    		ans[i] += cd * c[x];
    		if(a[x]){
    			q.push({c[x], x});
    		}
    	}
    	if(d){
    		ans[i] = 0;
    	}
    }
    for(int i = 1; i <= m; i++){
    	std::cout << ans[i] << "\n";
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