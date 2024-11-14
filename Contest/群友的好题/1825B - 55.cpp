// Problem: B. LuoTianyi and the Table
// Contest: Codeforces - Codeforces Round 872 (Div. 2)
// URL: https://codeforces.com/contest/1825/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

/**
 *                             _ooOoo_
 *                            o8888888o
 *                            88" . "88
 *                            (| -_- |)
 *                            O\  =  /O
 *                         ____/`---'\____
 *                       .'  \\|     |//  `.
 *                      /  \\|||  :  |||//  \
 *                     /  _||||| -:- |||||-  \
 *                     |   | \\\  -  /// |   |
 *                     | \_|  ''\---/''  |   |
 *                     \  .-\__  `-`  ___/-. /
 *                   ___`. .'  /--.--\  `. . __
 *                ."" '<  `.___\_<|>_/___.'  >'"".
 *               | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *               \  \ `-.   \_ __\ /__ _/   .-` /  /
 *          ======`-.____`-.___\_____/___.-`____.-'======
 *                             `=---='
 *          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 *                     佛祖保佑        永无BUG
 *            佛曰:
 *                   写字楼里写字间，写字间里程序员；
 *                   程序人员写程序，又拿程序换酒钱。
 *                   酒醒只在网上坐，酒醉还来网下眠；
 *                   酒醉酒醒日复日，网上网下年复年。
 *                   但愿老死电脑间，不愿鞠躬老板前；
 *                   奔驰宝马贵者趣，公交自行程序员。
 *                   别人笑我忒疯癫，我笑自己命太贱；
 *                   不见满街漂亮妹，哪个归得程序员？
 */
// #include<bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
//#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> PII;
#define endl "\n"
// #define int long long
using namespace std;
const int N = 4e6;
const int mod = 1000000007;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n * m);
  for (int i = 0; i < n * m; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int min1 = v[0], min2 = v[1];
  int max1 = v[m * n - 1], max2 = v[m * n - 2];
  cout << max((max(n, m) - 1) * (max1 - min1) +(min(n, m) - 1) * (max2 - min1) +(m * n - n - m + 1) * (max1 - min1),
        (max(n, m) - 1) * (max1 - min1) +(min(n, m) - 1) * (max1 - min2) +(m * n - n - m + 1) * (max1 - min1))
       << endl;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  // scanf("%d",&T);
  while (T--) {
    solve();
  }
  return 0;
}