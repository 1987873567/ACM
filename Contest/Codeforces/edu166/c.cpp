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
	int n, m;
	std::cin >> n >> m;
	int tot = n + m + 1;
	std::vector<i64> a(tot + 1), b(tot + 1);
	for (int i = 1; i <= tot; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= tot; i++) {
		std::cin >> b[i];
	}
	int id = 0;
	std::vector<int> ai(1), bi(1), ca(tot + 1), cb(tot + 1);
	std::vector<std::array<i64, 2>> sa(1), sb(1);
	for (int i = 1, N = n, M = m; i <= tot; i++){
		if(a[i] > b[i]){
			if(N)N--;
			ai.push_back(i);
			i64 aa = a[i], bb = b[i];
			aa += sa.back()[0];
			bb += sa.back()[1];
			sa.push_back({aa, bb});
		} else {
			if(M)M--;
			bi.push_back(i);
			i64 aa = a[i], bb = b[i];
			aa += sb.back()[0];
			bb += sb.back()[1];
			sb.push_back({aa, bb});
		}
		if(!N && !M && !id) id = i;
		ca[i] = ca[i - 1] + (a[i] > b[i]);
		cb[i] = cb[i - 1] + (b[i] > a[i]);
	}
	for (i64 i = 1, Sa = 0, Sb = 0, Ca = 0, Cb = 0; i <= tot; i++){
		if (Ca >= n) {
			
		}
	}
	// std::cout << id << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}