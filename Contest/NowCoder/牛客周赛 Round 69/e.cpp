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
    int n;
    std::cin >> n;
    std::vector<i64> v(n + 1), sum(n + 1), is(n + 1);
    std::map<i64, std::deque<int>> pos;
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
        is[i] = is[i - 1] + (v[i] > 0) ;
    }
    for(i64 i = 1, s = 0; i <= n; i++){
    	s += v[i];
    	if(s % 2 == 0 && sum[n] - sum[i] == s / 2 && is[n] - is[i] && is[i]) pos[s].push_back(i);
    }
    i64 s = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        s += v[i];
        i64 s2 = s + s;
        while(pos[s2].size() && pos[s2].front() < i) pos[s2].pop_front();
        if(!pos[s2].size()){
            pos.erase(s2);
            continue;
        }
        auto p = pos[s2].begin();
        while(p != pos[s2].end()){
            if(sum[n] - sum[*p] == s && is[n] - is[*p] && is[*p] - is[i] && is[i]){
                ans++;
            }
            p++;
        }
    }
    std::cout << ans << "\n";
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