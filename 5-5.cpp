// 個数制限なし部分和問題
// O(NW)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<bool>> dp(n+1, vector<bool>(w+1, false));
    // dp[i][j]：最初のi個の整数のみを用いて、重複ありを許して総和をとった値をjにすることが可能かどうか

    dp[0][0]=true;
    rep(i, n) {
        rep(j, w) {
            if (dp[i][j]) dp[i+1][j]=true;
            if (j>=a[i] && dp[i+1][j-a[i]]) dp[i+1][j]=true;
        }
    }
    if(dp[n][w]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
