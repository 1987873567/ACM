#include <bits/stdc++.h>
using namespace std;
#define int long long

void sovle(){
	std::string s;
	std::cin >> s;
	std::vector<int> c(26);
	for(auto i : s){
		c[i - 'a']++;
	}
	std::vector<pair<int, int>> v(26);
	for(int i = 0; i < 26; i++){
		if(c[i])
		v[i] = {c[i], i};
	}
	std::sort(v.begin(), v.end());
	std::string ans = "";
	while(ans.size() != s.size()){
		for(auto &[cc, i] : v){
			if(cc){
				cc--;
				ans += i + 'a';
			}
		}
		while(v.size() && v.begin()->first == 0) v.erase(v.begin());
	}
	int flag = 1;
	if(s.size() >= 2){
		if(ans[0] == ans[1])flag = 0;
	}
	if(s.size() >= 3){
		if(ans[0] == ans[2])flag = 0;
	}
	if(flag){
		std::cout << "YES\n";
		std::cout << ans << "\n";
	}else{
		std::cout << "NO\n";
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