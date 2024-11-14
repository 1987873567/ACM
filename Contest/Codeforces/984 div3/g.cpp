#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

i64 ask(i64 l, i64 r) {
    std::cout << "xor " << l << " " << r << std::endl;
    i64 x;
    std::cin >> x;
    if(x == -1) exit(0);
    return x;
}

void solve() {
    i64 n;
    std::cin >> n;
    i64 l = 0, r = n + 1;
    i64 a, b, c;
    while(l + 1 != r){
        i64 m = (l + r) >> 1;
        i64 x = ask(1, m);
        if(x){
            r = m;
        } else {
            l = m;
        }
    }
    a = r;
    l = a, r = n + 1;
    while(l + 1 != r){
        i64 m = (l + r) >> 1;
        i64 x = ask(m, n);
        if(x){
            r = m;
        } else {
            l = m;
        }
    }
    c = r;
    l = b, r = n + 1;
    while(l + 1 != r){
        i64 m = (l + r) >> 1;
        i64 x = ask(b + 1, m);
        if(x){
            r = m;
        } else {
            l = m;
        }
    }
    c = r;
    std::cout << "ans " << a << " " << b << " " << c << std::endl;
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