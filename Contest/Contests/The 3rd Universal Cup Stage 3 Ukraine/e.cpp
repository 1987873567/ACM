#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
const int mod = 998244353;
int qpow(int x, int y){
    int res = 1;
    for(;y; y >>= 1, x = x * x % mod){
        if(y & 1) res = res * x % mod;
    }
    return res % mod;
}
int C(int n,int m){
    int x=1;
    for(int i=1;i<=m;i++){
        x*=(n-i+1);
    }
    for(int i=1;i<=m;i++)
        x/=i;
    return x;
}
void sovle(int n, int m){
    // int n, m;
    std::cin >> n >> m;
    int ans=0;
    for(int x=2;x<=m;x++){
        for(int i=1;i<=n;i++){
            int y=qpow(x-1,n-i)*qpow(m-x+1,i);
                ans+=C(n,i)*(2*(y-1)+1);
        }
    }
    // std::cout << n << " " << m << ": ";
    cout<<ans+2*qpow(m,n)-1<< " " << ans << "\n";
}

signed main(){
    std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while(_--){
        // int n = 10, m = 10;
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
                sovle(0, 0);
        //     }
        // }
    }
    return 0;
}