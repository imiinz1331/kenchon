#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> B[i];
    }

    //A,Bをそれぞれ昇順ソート
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    ll ans = 0;
    ll a=0,b=0;
    //A,Bの何番目を使うか
    //小さいものからペアにしていき、Bの方が小さいときはBの一つ大きいもので調べてみる
    while(a<N && b<N){
        if(A[a]<B[b]){
            ans ++;
            a++;
        }
        b++;
    }
    cout << ans << endl;
}
