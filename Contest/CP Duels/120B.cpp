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
	std::ifstream input;
	input.open("input.txt");
	int n, k;
	input >> n >> k;
	int pre = -1, flag = 0;
	k--;
	for(int i = 0, x; i < n; i++){
		input >> x;
		if(x == 1){
			if(pre == -1)pre = i;
			if(flag == 0 && i >= k){
				k = i;
				flag = 1;
			}
		}
	}
	std::ofstream output;
	output.open("output.txt");
	if(!flag) k = pre;
	// std::cout << k + 1 << std::endl;
	output << k + 1 << "\n";
	output.close();
	input.close();
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