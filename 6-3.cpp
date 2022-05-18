#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    a.push_back(0); // 常に4個選べることにして，0も選べるようにする
    vector<ll> b; // 2個ずつの組み合わせの集合
    rep(i, a.size()){
        rep(j, a.size()){
            b.push_back(a[i]+a[j]);
        }
    }
    sort(b.begin(), b.end());
    ll res = 0;
    for(ll i : b) {
        auto it = upper_bound(b.begin(), b.end(), m-i); // 指定した値より大きいイテレータを返す
        if (it == b.begin()) continue;
        it--;
        res = max(res, i + *it);
    }
    cout << res << endl;
    return 0;
}
