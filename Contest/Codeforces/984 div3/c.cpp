#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "NO\n"
#define YES std::cout << "YES\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
    std::string s;
    std::cin >> s;
    std::set<int> pos;
    int n = s.size() - 1;
    for(int i = 0; i <= n; i++){
        if(s.substr(i, 4) == "1100"){
            pos.insert(i);
        }
    }

    int q;
    std::cin >> q;
    while(q--){
        int p, v;
        std::cin >> p >> v;
        p--;
        int ans;
        if(s[p] - '0' == v) {
            ans = pos.size();
        } else {
            int l = std::max(0, p - 3), r = std::min(p + 3, n);
            s[p] = char(v + '0');
            for(int i = l; i <= r; i++){
                if(s.substr(i, 4) == "1100"){
                    pos.insert(i);
                } else {
                    if(pos.count(i))pos.erase(i);
                }
            }
            ans = pos.size();
        }
        if(ans){
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

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}