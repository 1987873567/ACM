#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void sovle(){
	int n;
	std::cin >> n;
	std::vector<int> p(n + 1);
	std::vector<int> q(n + 1);
	for(int i = 1; i <= n; i++){
		std::cin >> p[i];
	}
	for(int i=1;i<=n;i++){
		if(!q[i]){
			int x=i;
			while(!q[x]){
				cout<<p[x]<<" ";
				q[x]=1;
				x=p[x];
			}
		}
	}
	cout<<"\n";
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