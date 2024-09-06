#include <bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void solve() {
    int n, m, pp;
    std::string s;
    std::cin >> n >> m >> pp >> s;
    pp--;

    std::stack<int> st;
    std::vector<int> pi(n);
    for(int i = 0; i < n; i++){
        if (s[i] == '(') {
            st.push(i);
        } else {
            pi[st.top()] = i;
            pi[i] = st.top();
            st.pop();
        }
    }

    std::string op;
    std::cin >> op;
    std::list<int> pos(all(pi));
    auto p = pos.begin();
    __gnu_pbds::gp_hash_table<int, decltype(p)> id;
    for(;p != pos.end(); p++){
        id[*p] = p;
    }
    p = id[pi[pp]];
    for(auto i : op){
        if (i == 'L') {
            p = std::prev(p);
        } else if (i == 'R'){
            p = std::next(p);
        } else {
            if(s[pi[*p]] == ')')
                p = id[pi[*p]];
            int po = pi[*p];
            while (*p != po) {
                pos.erase(p++);
            }
            p = pos.erase(p);
            if(p == pos.end()) p = std::prev(p);
        }
    }
    for(auto i : pos) {
        std::cout << s[pi[i]];
    }
    std::cout << "\n";
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