#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)

/*
N個の正の整数 ao, a1,…,aN-1 と正の整数 W が与えられます.こ
が何通りあるかを O(NW) で求めるアルゴリズムを設計してください
*/

int main() {
    string s, t, ans;
    cin >> s >> t;
    int n, m;
    n = s.length();
    m = t.length();

    vector<vector<char>> dp(n, vector<char>(m));

    int x = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i] == t[j]) {
                x = 
                dp[i][j] = s[i];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i] == t[j]) dp[i][j] = s[i];
        }
    }
    
    cout << ans << endl;
    return 0;
}
