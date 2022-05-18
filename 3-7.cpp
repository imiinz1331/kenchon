#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    ll ans=0;
    // +をいれる入れないの2^(N-1)通りで全探索
    for(int bit = 0; bit < (1<<(n-1)); bit++){
        ll sum = 0;
        rep(i, n){
            sum *= 10;
            sum += s[i]-'0'; // 文字をintに変換
            if(bit&(1<<i)){ // +があったら足す
                // cout<<sum<<endl;
                ans += sum;
                sum = 0;
            }
        }
        ans += sum;
    }
    cout<<ans<<endl;
    return 0;
}
