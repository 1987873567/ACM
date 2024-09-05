#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

std::set<i64> x;
std::vector<i64> p(34, 1);
struct node{
    int ctz, cto, len;
    i64 x;
};
void init() {
    for(int i = 1; i <= 31; i++) {
        p[i] = p[i - 1] * 2;
    }
    std::queue<node> q;
    q.push({1, 0, 0});
    while (q.size()) {
        auto [ctz, cto, len, nx] = q.front();
        q.pop();
        if (ctz == cto) {
            x.insert(nx);
        }
        for (int i = 0 ; i <= 1; i++) {
            i64 dx = nx + p[len + 1] * i;
            int dz = ctz, d1 = cto;
            if(i) d1++;
            else if(!d1) dz++;
            if (dx <= 1e9 && len + 1 <= 29  && d1 <= dz && 28 - len >= dz - d1) {
                q.push({dz, d1, len + 1, dx});
            }
        }
    }
}

void solve() {
    int l, r;
    std::cin >> l >> r;
    auto p = x.lower_bound(l);
    int ans = -1;
    if (p != x.end() && *p <= r) {
        ans = *p;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    // Rand.seed(time(0));
    init();

    std::cout << *prev(x.end()) << "\n";
    //999993344
    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}