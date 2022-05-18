#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

void func(ll n, ll tmp, int use, ll &ans){
    if (tmp>n) return;
    if (use==0b111) ans++;
    func(n, tmp * 10 + 7, use | 0b001, ans); //7を追加
    func(n, tmp * 10 + 5, use | 0b010, ans); //5を追加
    func(n, tmp * 10 + 3, use | 0b100, ans); //3を追加
}


int main(){
    ll n;
    cin>>n;
    ll ans=0;
    func(n, 0, 0, ans);
    cout << ans << endl;
    return 0;
}
