#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
i64 p[30] = {1};
void solve() {
    for(int i = 1; i <= 20; i++){
        p[i] = p[i - 1] * 10;
    }
    i64 n, d;
    std::cin >> n >> d;
    i64 tl = n - d, tr = n;
    std::string R = std::to_string(tr);
    std::reverse(all(R));
    auto get = [&](i64 x){
    	i64 res = 0;
    	for(int i = 0; i < x; i++){
    		res += p[i] * 9;
    	}
    	return res;
    };
    for(int i = R.size() - 1; i > 0; i--){
        i64 t = get(i);
        i64 m = n % p[i];
        if(m >= t){
            std::cout << n << "\n";
            return;
        } else {
            i64 tt = n - m;
            int j = i;
            while(j < R.size() && R[j] == '0') j++;
            tt -= p[j];
            tt += t;
            if(n - tt <= d && tt <= n){
                std::cout << tt << "\n";
                return;
            }
        }
    }
    std::cout << n << "\n";
}

int main() {
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