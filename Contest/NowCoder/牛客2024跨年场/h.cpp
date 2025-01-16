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
    std::vector<std::vector<int>> g(30);
    std::vector<int> vis(30), r(30), size(30);
    for(int i = 0; i < 19; i++){
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        r[a]++, r[b]++;
    }
    int cnt = 22;
    int ans = 0;
    for(int i = 1; i <= 22; i++){
    	if(!vis[i] && r[i] == 1){
    		std::queue<int> q;
    		q.push(i);
    		int res = 0;
    		while(q.size()){
    			int x = q.front();
    			q.pop();
    			res++;
    			cnt--;
    			vis[x] = 1;
    			for(auto y : g[x]){
    				if(--r[y] == 1){
    					q.push(y);
    				}
    			}
    		}
    		ans += (res == 5);
    	}
    }
    if(ans == 3 && cnt == 4){
    	std::cout << "2025\n";
    } else {
    	std::cout << "2024\n";
    }
}

int main() {
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