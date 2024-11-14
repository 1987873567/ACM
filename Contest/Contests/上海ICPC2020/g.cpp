/*
0 0 
2 3 4         5  1 
9 11 13       8  2 
21 24 27      11 3 
38 42 46      14 4 
60 65 70      17 5
87 93 99      20 6
119 126 133    
156 164 172 198 207 
216 245 255 265 297 308 319 354 366 378 416 429 442 483 497 511 555 570 585 632 648 
664 714 731 748 801 819 837 893 912 931 990 1010 1030 1092 1113 1134 1199 1221 1243 1311 
1334 1357 1428 1452 1476 1550 1575 1600 1677 1703 1729 1809 1836 1863 1946 1974 2002 2088 
2117 2146 2235 2265 2295 2387 2418 2449 2544 2576 2608 2706 2739

*/

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
	i64 n;
	std::cin >> n;
	if(n <= 2){
		std::cout << "0\n";
		return;
	}

	int t = n / 3;
	

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