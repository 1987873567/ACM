#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
using namespace __gnu_pbds;
using namespace std;
struct DSU {
    std::vector<int> f, cnt;
    DSU(int n) {
        f.resize(n + 1);
        cnt.resize(n + 1);
        iota(all(f), 0);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    void add(int x, int y) {
        x = find(x), y = find(y);
        // if (x > y) std::swap(x, y);
        if (x != y) {
            f[y] = x;
            cnt[x] += cnt[y];
        }
    }
    bool s(int x, int y) { return find(x) == find(y); }
    int c(int x) { return cnt[find(x)]; }
};
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type,std::less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> pbds;
void solve() {
	int n,q;
	std::cin >> n >> q;
	std::vector<pbds> v(n + 1);
	DSU f(n + 1);
	for(int i = 1; i <= n; i++){
		v[i].insert(i);
	}
	auto print = [](auto &trr, int a){
		std::cerr << "id:" << a << "\n";
		for(auto it = trr.begin(); it != trr.end(); it++){
			std::cerr << *it << " ";
		}
		std::cerr << "\n";
	};
	while(q--){
		int op, a, b;
		std::cin >> op >> a >> b;
		if(op == 1){
			if(!f.s(a, b)){
				// print(v[f.find(a)], a);
				// print(v[f.find(b)], b);
				int fa = f.find(a),fb = f.find(b);

				if(v[fa].size() < v[fb].size()){
					for (auto it = v[fa].begin(); it != v[fa].end(); ++it) {
                		v[fb].insert(*it);
            		}
            		v[fa].clear();
            		f.add(b, a);
				} else{
					for (auto it = v[fb].begin(); it != v[fb].end(); ++it) {
                		v[fa].insert(*it);
            		}
            		v[fb].clear();
            		f.add(a, b);
				}
				
				// v[fa].join(v[fb]);
				
			}
		}else{
			if(v[f.find(a)].size() < b)std::cout << "-1\n";
			else {
				auto ans = v[f.find(a)].find_by_order(v[f.find(a)].size() - b);
				std::cout << (*ans) << "\n";
			}
		}
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