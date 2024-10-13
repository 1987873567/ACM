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
	std::vector<std::vector<i64>> sum(26, std::vector<i64>(1));
	/*
	*/
	std::string s;
	std::cin >> s;
	i64  n = s.size();
	s = ' ' + s;
	for(i64 i = 1; i <= n; i++){
		sum[s[i] - 'A'].push_back(i);
	}
	for(auto &v : sum){
		for(i64 j = 1; j < v.size(); j++){
			v[j] += v[j - 1];
		}
	}
	i64 ans = 0;
	for(auto v : sum){
		i64 nn = v.size() - 1;
		for(i64 i = 1; i < nn; i++){
			i64 j = i;
			while(j <= nn && v[j] - v[i] + 1 < 3)j++;
            if(v[j] - v[i] + 1 < 3) continue;
            ans += (v[nn] - v[j - 1]) - (v[i] - v[i - 1]) * (nn - j + 1);
            ans -= (nn - j + 1);
		}
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
/*
ABCACC
123456
4 - 1 - 1 = 2

5 - 3 - 1 = 1
6 - 3 - 1 = 2
*/