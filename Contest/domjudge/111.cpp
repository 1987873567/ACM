#include <bits/stdc++.h>

#define int long long

void solve() {
    const int mod = 1e9 + 7;
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> f(2, std::vector<int>(m + 1));
    int i = 0;
    int x;
    std::cin >> x;
    if(x == 0) {
        for(int j = 1; j <= m; j++) f[i][j] = 1;
    } else {
        f[i][x] = 1;
    }
    n--;
    for(; n; n--, i ^= 1) {
        std::cin >> x;
        if(x == 0) {
            for(int j = 1; j <= m; j++) {
                for(int k = -1; k <= 1; k++) {
                    if(j + k >= 1 && j + k <= m) {
                        f[i ^ 1][j + k] = (f[i ^ 1][j + k] + f[i][j]) % mod;
                    } 
                }
            }
        }else {
            for(int k = -1; k <= 1; k++) {
                if(x + k >= 1 && x + k <= m) {
                    f[i ^ 1][x] = (f[i ^ 1][x] + f[i][x + k]) % mod;
                }
            }
        }
        for(int j = 1; j <= m; j++) f[i][j] = 0;
    }
    int ans = 0;
    for(int j = 1; j <= m; j++) {
        ans = (ans + f[i][j]) % mod;
    }
    std::cout << ans;
}

signed main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) solve();

    return 0;
}
