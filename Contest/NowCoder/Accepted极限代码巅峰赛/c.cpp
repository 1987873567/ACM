#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};


/*
---------------莫队写法 · 寄------------
void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> p(n + 1), id(n + 1);
    std::iota(all(p), 0);
    std::iota(all(id), 0);
    std::vector<std::pair<int,int>> ab(m);
    for(auto &[a, b] : ab){
        std::cin >> a >> b;
    }
    std::vector<std::array<int, 4>> op(q);
    std::vector<int> ans(q);
    for(int i = 0; i < q; i++){
        int l, r, k;
        std::cin >> l >> r >> k;
        op[i] = {l, r, k, i};
    }
    std::sort(all(op));
    auto add = [&](int l, int r){
        std::swap(id[p[l]], id[p[r]]);
        std::swap(p[l], p[r]);
    };
    auto del = [&](int l, int r){
        std::swap(p[id[l]], p[id[r]]);
        std::swap(id[l], id[r]);
    };
    int L = 1, R = 0;
    for(int i = 0; i < q; i++){
        auto [l, r, k, Id] = op[i];
        while(L > l)
            L--, del(ab[L - 1].first, ab[L - 1].second);
        while(R < r)
            R++, add(ab[R - 1].first, ab[R - 1].second);
        while(L < l)
            del(ab[L - 1].first, ab[L - 1].second), L++;
        while(R > r)
            add(ab[R - 1].first, ab[R - 1].second), R--;
        ans[Id] = p[k];
    }
    for(int i = 0; i < q; i++){
        std::cout << ans[i] << "\n";
    }
}

*/

void solve(){
	
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