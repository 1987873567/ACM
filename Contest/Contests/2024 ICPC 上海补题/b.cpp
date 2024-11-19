#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
int t,n,m,k,x,y,z,flag;

signed main()
{
//    IOS;
    cin>>n>>m;
    vector<set<int>> b(n+1);
    vector<vector<int>> e(n+1);
    vector<pair<int,int>> ans;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        b[x].insert(y);
        b[y].insert(x);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<int> a(n+10);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int num=2;
    function<void(int,int)> dfs=[&](int x,int f)->void{

        for(auto i:e[a[x]]){
            auto j=b[i].lower_bound(a[x]);
            if(j!=b[i].end() && *j == a[x])
                b[i].erase(j);
        }
        
        while(b[a[x]].size()){
            auto j=b[a[x]].lower_bound(a[num]);
            if(j!=b[a[x]].end()&&*j==a[num]){
            	// b[a[x]].erase(j);
                dfs(num++,f+1);
            }
            else{
                ans.emplace_back(a[x],a[num]);
                dfs(num++,f+1);
            }

        }
        if(num>=n+1){
            return;
        }
        if(f==1&&num<=n){
            dfs(num++,1);
        }
    };
    dfs(1,1);
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    return 0;
}