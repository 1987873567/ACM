#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;

#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(x) x.begin(), x.end()

// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
struct node{
    std::string name;
    std::vector<node*> next;
    int id,  fa;
};
void solve() {
    int n, m;
    std::cin >> n >> m;
    int tot = 0;
	std::vector<int> sum(1);
    node root;
    root.name = "";
    root.id = 0;
    auto Add = [&](auto &&self, auto &path, int p, node *Root, int val){
        if(p == path.size())return;
        int flag = 0;
        for(auto i : Root->next){
            if(i->name == path[p]){
                flag = 1;
                self(self, path, p + 1, i, val);
            }
        }
        if(!flag){
            node *temp = new node;
            temp->name = path[p];
            temp->id = ++tot;
            sum.push_back(p == path.size() - 1 ? val : 0);
            temp->fa = Root->id;
            Root->next.push_back(temp);
            self(self, path, p + 1, Root->next.back(), val);
        }

    };
    auto add = [&](std::string &s, int val){
        s += '/';
        int pre = 0;
        int p = s.find('/', pre);
        std::vector<std::string> path;
        while(p != s.npos){
            std::string temp = s.substr(pre, p - pre);
            path.push_back(temp);
            pre = p + 1;
            p = s.find('/', p + 1);
        }
        Add(Add, path, 0, &root, val);
    };

    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;
        add(s, 0);
    }
    for(int i = 0; i < m; i++){
        std::string s;
        std::cin >> s;
        add(s, 1);
    }
    int ans = 0;
    
    auto dfs = [&](auto &&self, node *Root) -> void{
        for(auto i : Root->next){
        	if(!i->name.size())continue;
            self(self, i);
            sum[i->fa] += sum[i->id];
        }
    };
    dfs(dfs, &root);
    auto dfs1 = [&](auto &&self, node *Root) -> void{
        if(sum[Root->id] == 0 && Root->id != 0){
        	// std::cout << Root->name << "\n";
            ans++;
            return;
        }
        for(auto i : Root->next){
        	if(!i->name.size())continue;
            self(self, i);
        }
    };
    dfs1(dfs1, &root);
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