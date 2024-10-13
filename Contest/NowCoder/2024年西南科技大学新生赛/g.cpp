#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

ld get(ld a,ld b,ld c,ld d){
    return std::sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void solve() {
    ld a,b,c,d;
    std::cin >> a >> b >> c >> d;
    if(get(-a,b,c,d) < get(a,-b,c,d)){
    	std::cout << "y\n";
    }else{
    	std::cout << "x\n";
    }
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