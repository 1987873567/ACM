#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(x) x.begin(), x.end()

std::default_random_engine Rand;
std::uniform_int_distribution<i64> r1(1, 1e18);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
const i64 mod = (1ll << 60 - 1);
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::set<int>> mp(n);
    std::vector<i64> c(101);
    for(int i = 0; i <= 100; i++){
        c[i] = r1(Rand) % mod;
    }
    auto cal = [&](auto &x){
        i64 sum = 0;
        for(auto i : x){
            sum += c[i];
            sum %= mod;
        }
        return sum;
    };
    for(int i = 0; i < n; i++){
        int m;
        std::cin >> m;
        std::vector<int> v(m);
        for(int j = 0; j < m; j++){
            std::cin >> v[j];
        }
        mp[i].insert(all(v));
    }
    std::vector<int> ans(n, 1);
    for(int a = 0; a < n; a++){
    	for(int b = 0; b < n; b++){
    		int cnt = 0;
    		if(a == b)continue;
    		for(auto x : mp[a]){
    			if(mp[b].count(x))cnt++;
    		}
    		if(cnt == mp[a].size()) ans[b] = 0;
    	}
    }
    for(int i = 0; i < n; i++){
        if(ans[i]){
            YES;
        } else {
            NO;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}