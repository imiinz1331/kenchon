#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<int,int> P;

int main() {
    // 入力
    ll n,w,k;
    cin >> n;
    vector <ll> a(n);
    rep(i,n){
        cin >> a.at(i);
    }
    cin >> w >> k;

    //dpで考える
    vector <vector<ll>> c(n+1,vector<ll>(w+1,LLONG_MAX));
    c[0][a.at(0)-1]=1;


    for(ll i=1;i<n;i++){
        c[i][a[i]]=1;
        for(ll j=0;j<w;j++){
            if(c[i-1][j]!=0){
                c[i][j+a[i]]=min(c[i-1][j]+1,c[i][j+a[i]]);
                c[i][j]=min(c[i-1][j],c[i][j]);
            }
            if(j==w-1 && c[i][j]<=k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;

}
