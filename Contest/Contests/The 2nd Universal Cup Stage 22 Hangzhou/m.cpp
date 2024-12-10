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
	int n;
	std::cin >> n;
	std::vector<i64> v(n + 1), sum(n + 1);
	for(int i = 1; i <= n; i++){
		std::cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}
	std::vector<int> pre(n + 1), suf(n + 1);
	suf[n] = n;
	for(int i = 2; i <= n; i++){
		if(v[i - 1] > v[i]){
			pre[i] = pre[i - 1];
		} else {
			pre[i] = i - 1;
		}
	}
	for(int i = n - 1; i >= 1; i--){
		if(v[i + 1] > v[i]){
			suf[i] = suf[i + 1];
		} else {
			suf[i] = i;
		}
	}
	auto bf = [&](i64 s, int len, int l, int r, int step) -> ld{
		ld res = 1.0 * s / len;
		while(l != r){
			s += v[l];
			len++;
			ld t = 1.0 * s / len;
			res = std::max(res, t);
            l += step;
		}
		return res;
	};
	auto f = [&](int L, int x, int R) -> ld{
		return std::max(bf(sum[R] - sum[x - 2], R - x + 2, x - 1, L + 1, -1), bf(sum[x + 1] - sum[L], x + 1 - L, x + 2, R + 1, 1));
	};
	ld ans = 0;
	for(int i = 2; i < n; i++){
		if(v[i - 1] > v[i] && v[i] < v[i + 1]){
			ans = std::max(f(pre[i], i, suf[i]), ans);		}
	}
	std::cout << ans << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    std::cout << std::fixed << std::setprecision(10);

    while (_--) {
        solve();
    }
    return 0;
}