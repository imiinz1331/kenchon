#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

/*
N個の正の整数 ao, a1,…,aN-1 と正の整数 W が与えられます.こ
が何通りあるかを O(NW) で求めるアルゴリズムを設計してください
*/

int main()
{
    //入力
    int n, w;
    cin >> n >> w;
    w++;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    //dp[i][j] = a0 - aiを用いて、jを作ることができる -> 1, 作ることができない -> 0
    bool dp[n][w];

    //初期化
    rep(i, n)rep(j, w){
        dp[i][j] = 0;
        if(j == 0) dp[i][j] = 1;
    }

    rep(i, n){
        //a[i]を追加する
        rep(j, w){
            if(i == 0){
                if(j == a[i]){
                    dp[i][j] = 1;
                }
            }
            else{
                if(j - a[i] >= 0 && dp[i - 1][j - a[i]] == 1){
                    dp[i][j] = 1;
                }
                if(dp[i - 1][j]) dp[i][j] = 1;
            }
        }
    }
    int ans = 0;

    rep(j, w){
        if(dp[n - 1][j] == 1) ans++;
    }

    cout << ans << endl;

}
