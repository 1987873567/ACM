#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void sovle(){
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int ans = 0, flag = 0;
	int C1 = (s[0] == '1');
	for(int i = 1; i < n; i++){
		if(s[i] == '0' && s[i - 1] == '0') flag = 1;
		if(s[i] == '1') C1 ++;
	}
	if(flag == 0 && s[0] == '1' && s.back() == '1'){
		int c1 = 1e9;
		s += '0';
		for(int i = 0, ss = 0; i <= n; i++){
			if(s[i] == '1') ss ++;
			else c1 = std::min(c1, ss), ss = 0;
		}
		std::cout <<  C1 + c1 << "\n";
	} else {
		std::cout << C1 << "\n";
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