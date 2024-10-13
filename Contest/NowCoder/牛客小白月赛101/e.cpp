#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 1e6 + 10;
struct Euler{
    std::vector<int> p;
    std::vector<bool> vis;
    int n;
    Euler(int n){init(n);}
    Euler(){init(0);}
    void init(int _n){
        n=_n;
        p.resize(0),vis.resize(n+1);
        vis[0]=vis[1]=1;
        for (int i = 2; i <= n; ++i) {
            if (!vis[i]) {
                p.push_back(i);
            }
            for (int j : p) {
                if (i * j > n) break;
                vis[i * j] = true;
                if (i % j == 0) {
                    break;
                }
            }
        }
    }
    bool is_p(int x){
        if(x>n){
            init(x*2);
        }
        return !vis[x];
    }
    std::vector<int> get_p(){return p;}
}P(N);

int f[N], v[N];

void solve() {
	int n;
	std::cin >> n;
	std::unordered_map<int, int> c;
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
		c[v[i]]++;
	}

	for(auto &[x, cnt] : c){
		for(int j = x; j <= 1e6; j += x){
			f[j]++;
		}
	}
	
	int ans = 0;
	for(auto &[x, cnt] : c){
		int y = 1, xx = x;
		for(int j = 0; P.p[j] * P.p[j] <= xx; j++){
			int t = P.p[j], cc = 1;
			while(xx % t == 0){
				cc++;
				xx /= t;
			}
			y *= cc;
		}
		if(xx != 1) y *= 2;
		if(y == f[x]) ans += 1;
	}
	std::cout << ans << "\n";
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