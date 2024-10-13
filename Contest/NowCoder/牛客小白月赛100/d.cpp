#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
void solve() {
    int n, m, sx, sy;
    std::cin >> n >> m >> sx >> sy;
    sx--, sy--;
    std::string mp[n];
    for(int i = 0; i < n; i++){
        std::cin >> mp[i];
    }

    auto c=[&](int x,int y) {
        return x < n && x >=0 && y < m && y >= 0 && mp[x][y] != '#';
    };

    auto bfs = [&](std::vector<std::pair<int, int>> &p){
        std::priority_queue<std::array<int, 3>> q;
        std::vector<std::vector<int>> dis(n, std::vector<int>(m,1e9));
        for(auto [x, y] : p){
            q.push({0, x, y});
            dis[x][y] = 0;
        }    
        
        int res = 0;
        while(q.size()){
            auto [p, x, y] = q.top();
            q.pop();
            for(int i = 0; i < 4; i++){
                int dx = x + d[i][0], dy = y + d[i][1];
                if(c(dx, dy) && dis[dx][dy] > dis[x][y] + 1){
                    dis[dx][dy] = dis[x][y] + 1;
                    q.push({-dis[dx][dy], dx, dy});
                }
            }
        }
        return dis;
    };
    std::vector<std::pair<int,int>> pos;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == '@'){
                pos.push_back({i,j});
            }
        }
    }

    auto dis1 = bfs(pos);
    std::priority_queue<std::array<i64, 5>> q;
    q.push({0, sx, sy, sx, sy});
    const int N = 1e9;
    // std::vector<std::vector<std::array<int,2> > > dis(n + 1, std::vector<std::array<int, 2>>(n + 1,{N, N}));
    std::vector<std::vector<i64> > dis(n, std::vector<i64>(m,1e9));
    dis[sx][sy] = 0;
    i64 ans = 1e9;
    while(q.size()){
        auto [p, x, y, a, b] = q.top();
        q.pop();
        if(mp[x][y] == '@') {
            ans = std::min(dis[x][y] + dis1[a][b], ans);
        }
        for(int i = 0; i < 4; i++){
            int dx = x + d[i][0], dy = y + d[i][1], da = a + d[(i + 2) % 4][0], db = b + d[(i + 2) % 4][1];
            if (c(dx,dy) && c(da,db)) {
                if(dis[dx][dy] > dis[x][y] + 1){
                    dis[dx][dy] = dis[x][y] + 1;
                    q.push({-dis[dx][dy], dx, dy, da, db});
                }

            }
        }
    }
    if(ans >= 1e8)ans = -1;
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