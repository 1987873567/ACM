#include<bits/stdc++.h>
using ld = long double;
using i64 = long long;
#define all(x) x.begin(), x.end()

void solve(){
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;
  int A, T, C, G, ans = 0;
  A = T = C = G = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == 'A' && b[i] == 'A') A++;
    if(a[i] == 'T' && b[i] == 'T') T++;
    if(a[i] == 'C' && b[i] == 'C') C++;
    if(a[i] == 'G' && b[i] == 'G') G++;
    if(a[i] == 'A' && (b[i] == 'C' || b[i] == 'G')) ans++;
    if(a[i] == 'T' && (b[i] == 'C' || b[i] == 'G')) ans++;
    if(a[i] == 'C' && (b[i] == 'A' || b[i] == 'T')) ans++;
    if(a[i] == 'G' && (b[i] == 'A' || b[i] == 'T')) ans++;
  }
  int t = std::min(A, T);
  A -= t;
  T -= t;
  ans += t;
  ans += A;
  ans += T;
  t = std::min(G, C);
  G -= t;
  C -= t;
  ans += t;
  ans += G;
  ans += C;
  std::cout << ans << "\n";
}

signed main(){
  std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
  int _ = 1;
  while(_--){
    solve();
  }
  return 0;
}