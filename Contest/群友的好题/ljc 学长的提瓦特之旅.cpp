#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "N0\n"
#define YES std::cout << "YE5\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
	int n;
	std::cin >> n;
	std::vector<i64> v(n);
	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}
	i64 ljc[3], lyc[3];
	for(int i = 0; i < 3; i++)std::cin >> ljc[i];
	for(int i = 0; i < 3; i++)std::cin >> lyc[i];
	for(int i = 0; i < ((n + 1) / 2); i++)ljc[1] += v[i];
	for(int i = ((n + 1) / 2); i < n; i++)lyc[2] -= v[i];
	lyc[2] = std::max(lyc[2], 0ll);
	lyc[1] = (lyc[1] - (i64)(ljc[2] / 2 + 0.5));
	ljc[1] = (ljc[1] - (i64)(lyc[2] / 2 + 0.5));
	if((!ljc[1] && !lyc[1]) || (!ljc[1])){
		NO;
		return;
	}
	if(!lyc[1]){
		YES;
		return;
	}
	i64 a = (ljc[0] + lyc[1] - 1) / lyc[1];
	i64 b = (lyc[0] + ljc[1] - 1) / ljc[1];
	if(n & 1){
		if(a > b){
			YES;
		}else{
			NO;
		}
	} else {
		if(a >= b){
			YES;
		}else{
			NO;
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