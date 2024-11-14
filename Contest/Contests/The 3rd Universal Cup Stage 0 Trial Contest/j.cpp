#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long

const int MAXN = 1e5 + 5;
int n;
ll m;
ll  a[MAXN];
int main()
{

    int i;
    cin>>n>>m;
    ll sum = 0;
    for (i = 1; i <= n; ++i)
        cin>>a[i];
    for (i = 1; i <= n; ++i)
    {
        ll x = a[i];
        if ((__int128)(x - 1) * i + sum >= (__int128)m)
        {
            break;
        }
        sum += x;
    }
    cout<<i-1<<endl;
    return 0;
}