#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
#define int long long
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(a) a.begin(), a.end()
#define CF cout.flush();
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::UNIFORM_INT_DISTRIBUTION<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 1e6;
constexpr int mod = 1e9 + 7;
constexpr ld eps = 1e-6;

constexpr std::string C = "BGRY";

int id (int x, int y) {
	if(x > y) std::swap(x, y);
	return y * (y - 1) / 2 + x;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::array<int,2>> v(n);
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;
        for(int j = 0; j < 2; j++) {
        	v[i][j] = C.find(s[j]);
        }
    }
    std::vector<std::array<int, 6>> pre(n), suf(n);
    for (int i = 0; i < n; i++) {
    	if (i == 0) {
    		pre[i].fill(-1);
    	} else {
    		pre[i] = pre[i - 1];
    	}
    	pre[i][id(v[i][0], v[i][1])] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
    	if (i == n - 1) {
    		suf[i].fill(n);
    	} else {
    		suf[i] = suf[i + 1];
    	}
    	suf[i][id(v[i][0], v[i][1])] = i;
    }
    while (q--) {
    	int x, y;
    	std::cin >> x >> y;
    	x--, y--;

    	if (x > y) std::swap(x, y);

    	int ans = 1e9;

    	for (auto a : v[x]) {
    		for(auto b : v[y]){
    			if(a == b) {
    				ans = std::min(ans, y - x);
    			} else {
    				int w = id(a, b);
    				for (auto c : {pre[y][w], suf[x][w]}) {
    					if (c >= 0 && c < n)ans = std::min(ans, std::abs(c - x) + std::abs(c - y));
    				}
    			}
    		}
    	}

    	if (ans > 1e8) ans = -1;
    	std::cout << ans << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

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