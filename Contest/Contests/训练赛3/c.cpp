#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

std::default_random_engine Rand;
const i64 mod = (1ll << 60);
std::uniform_int_distribution<i64> r1(1, mod - 1);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<i64> hash(n + 1), a(n + 1), b(n + 1);
	for(int i = 0; i <= n; i++) hash[i] = r1(Rand);
	for(int i = 1; i <= n; i++){
		std::cin >> a[i];
		a[i] += a[i - 1] + hash[a[i]];
	}
	for(int i = 1; i <= n; i++){
		std::cin >> b[i];
		b[i] += b[i - 1] + hash[b[i]];
	}
	while(q--){
		int l, r, L, R;
		std::cin >> l >> r >> L >> R;
		if((a[r] - a[l - 1] + mod) % mod == (b[R] - b[L - 1] + mod) % mod){
			YES;
		} else {
			NO;
		}
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}