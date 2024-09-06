// Problem: P10564 [ICPC2024 Xi'an I] Rubbish Sorting
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P10564?contestId=173404
// Memory Limit: 1 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using i64 = long long;
#define endl '\n'
#define NO std::cout << "No\n"
#define YES std::cout << "Yes\n"
#define all(a) a.begin(), a.end()
using PII = std::pair<int, int>;
// std::default_random_engine Rand;
// std::uniform_int_distribution<int> r1(1, 10), r2(1, 2e5), r3(1, 1e8);
// constexpr int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
constexpr int N = 2e8;
constexpr int mod = 1e9 + 7;
int t[N+10][27],tot=1;
vector<int> id(N+10,1e9);
void add(string &s,int x){
    int p=1;
    for(auto i:s){
        int c=i-'a';
        if(i=='_'){
            c=26;
        }
        if(!t[p][c])t[p][c]=++tot;
        p=t[p][c];
    }
    id[p]=min(id[p],x);
}
int ask(string &s){
    int p=1;
    for(auto i:s){
        int c=i-'a';
        if(i=='_')c=26;
        p=t[p][c];
        if(!p)return -1;
    }
    return id[p];
}
void solve() {
    int q;
    cin>>q;
    int mi=1e9;
    while(q--){
        int op;
        string s;
        cin>>op>>s;
        if(op==1){
            int x;
            cin>>x;
            mi=min(mi,x);
            for(int i=1;i<(1<<(int)s.size());i++){
                string t=s;
                for(int j=0;j<(int)s.size();j++){
                    if((i&(1<<j))==0){
                        t[j]='_';
                    }
                }
                while((int)t.size()<5)t+='_';
                add(t,x);
            }
            // cout<<"\n";
        }else{
            int ans=1e9,nn=0,f=1;
            for(int i=1;i<(1<<(int)s.size());i++){
                string t=s;
                int cnt=0;
                for(int j=0;j<(int)s.size();j++){
                    if((i&(1<<j))==0){
                        t[j]='_';
                        cnt++;
                    }
                }
                while((int)t.size()<5)t+='_',cnt++;
                int n=5-cnt;
                int x=ask(t);
                if(x!=-1){
                    f=0;
                    if(nn<n){
                        nn=n;
                        ans=x;
                    }else if(nn==n){
                        ans=min(ans,x);
                    }
                }
            }
            if(f){
                cout<<mi<<"\n";
            }else{
                cout<<ans<<"\n";
            }
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // Rand.seed(time(0));

    int _ = 1;

    // std::cin >> _;
    // _=raed();
    // scanf("%ld",&_);
    // std::cout<<std::fixed<<std::setprecision(2);

    while (_--) {
        solve();
    }
    return 0;
}