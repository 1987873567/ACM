#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int N, M, X0;
	std::cin >> N >> M >> X0;
	std::vector<int> A(M), B(M), S(M), T(M);

	for (int i = 0;i < M; i++) {
		std::cin >> A[i] >> B[i] >> S[i] >> T[i];
		A[i]--,B[i]--;
	}

	std::vector<std::array<int, 3>> v(M * 2);
	for (int i = 0; i < M; i++) {
		v[i * 2] = {S[i], 1, i};
		v[i * 2 + 1] = {T[i], 0, i};
	}
	std::sort(v.begin(), v.end());
	std::vector<int> X(M), temp(N);
	X[0] = X0;
	for (auto [x, op, i] : v) {
		if (op) {
			X[i] = std::max(X[i], temp[A[i]] - S[i]);
		} else {
			temp[B[i]] = std::max(temp[B[i]], T[i] + X[i]);
		}
	}
	for(int i = 1; i < M; i++) {
		std::cout << X[i] << " \n"[i == M - 1];
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}