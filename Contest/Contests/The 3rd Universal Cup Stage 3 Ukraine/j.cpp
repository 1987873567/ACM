#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void sovle(){
    int n;
    std::cin >> n;
    std::vector<int> v(n + 1);
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
    }
    std::vector<int> vis(n + 1);
    std::vector<int> p;
    int flag = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[v[i]]){
            int x = v[i], cnt = 0;
            std::vector<int> temp;
            while(!vis[x]){
                vis[x] = 1;
                x = v[x];       
                temp.push_back(x);
                cnt++;
            }
            if(temp.size() > p.size())p = temp;
            if(cnt == n){flag = 1;break;}
        }
    }
    if(flag){
        int ans = -1;
        int pos = 0;
        for(int i = 1; i <= n; i++){
            int t = std::min(v[i] - 1, i - 1) + std::min(n - v[i], n - i);
            if(t > ans){
                pos = i;
                ans = t;
            }
        }
        std::cout << ans << "\n";
        std::cout << "1\n" << pos << "\n";
    } else {
        std::cout << n << "\n";
        std::cout << p.size() << "\n";
        std::sort(all(p));
        for(auto i : p){
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

}

signed main(){
    std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while(_--){
        sovle();
    }
    return 0;
}