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
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    std::sort(all(a));
    std::priority_queue<int> q;
    int b = 1, ans = 0;
    for(int i = 0; i < n && b < 100; i++){
        while (a[i] > b && q.size() && b < 100) {
            ans++;
            b += q.top();
            q.pop();
        }
        if(a[i] <= b) q.push(a[i]);
    }
    while (q.size() && b < 100) {
         ans++;
         b += q.top();
         q.pop();
    }
    if(b < 100){
        ans = -1;
    }
    std::cout << ans << "\n";
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