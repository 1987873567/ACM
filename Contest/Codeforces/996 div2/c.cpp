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
    int n, m;
    std::cin >> n >> m;
    std::vector mp(n + 1, std::vector<i64>(m + 1));
    
    std::string s;
    std::cin >> s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            std::cin >> mp[i][j];
        }
    }
    auto ans = mp;
    std::vector<i64> l(m + 1), r(n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            r[i] += mp[i][j];
            l[j] += mp[i][j];
        }
    }
    i64 x = 1, y = 1, X = 0;
    mp[1][1] = (s[0] == 'D' ? -r[1] : -l[1]);
    r[1] += mp[1][1];
    l[1] += mp[1][1];
    for(int i = 0; i < s.size() - 1; i++){
        char op = s[i];
        if(op == 'D'){
            x++;
            if(op == s[i + 1]){
                mp[x][y] = X - r[x];
            } else {
                mp[x][y] = X - l[y];
            }

        } else {
            y++;
            if(op == s[i + 1]){
                mp[x][y] = X - l[y];
            } else {
                mp[x][y] = X - r[x];
            }
        }
        r[x] += mp[x][y];
        l[y] += mp[x][y];
    }
    mp[n][m] = X - r[n];
    r[n] += mp[n][m];
    l[m] += mp[n][m];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            std::cout << mp[i][j] << " \n"[j == m];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // Rand.seed(time(0));

    int _ = 1;

    std::cin >> _;
    // scanf("%ld",&_);
    // std::cout << std::fixed << std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}
/*

1
4 5
DRRRRDD
0 1 0 2 10
0 0 0 0 0
-1 0 -3 -3 0
0 0 0 -1 0

1
5 5
DDDDRRRR
0 25 2 9 11
0 6 13 20 22
0 17 24 1 8
0 3 10 12 19
0 0 0 0 0

*/