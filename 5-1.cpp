#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> c(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<int>> dp(n+1, vector<int>(3));

    for(int i = 0; i < 3; i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++) {
        dp[i][0] += max(dp[i-1][1]+a[i], dp[i-1][2]+a[i]);
        dp[i][1] += max(dp[i-1][0]+b[i], dp[i-1][2]+b[i]);
        dp[i][2] += max(dp[i-1][0]+c[i], dp[i-1][1]+c[i]);
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
    return 0;
}
