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
    int n, k;
    std::cin >> n >> k;
    std::map<int, int> c;
    for(int i = 0, x; i < n; i++){
        std::cin >> x;
        c[x]++;
    }
    std::vector<std::pair<int, int>> v(all(c));
    std::vector<std::vector<int>> t(1, std::vector<int>(1, 0));
    for(int i = 0; i < v.size(); i++){
        if(t.back().size() == 1){
            t.back().push_back(v[i].second);
        }else{
            if(v[i - 1].first + 1 == v[i].first){
                t.back().push_back(t.back().back() + v[i].second);
            }else{
                t.push_back(std::vector<int>(1, 0));
                t.back().push_back(v[i].second);
            }
        }
    }

    int ans = 0;
    for(auto &a : t){
        for(int i = 0; i < a.size(); i++){
            ans = std::max(ans, a[std::min((int)a.size() - 1, i + k)] - a[i]);
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

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}