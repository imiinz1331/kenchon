#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<ll,ll> P;

int main() {
    ll n,k,t1,t2,t3;
    cin >> n >> k;

    vector<ll> a(n);
    vector<P> b(n);

    rep(i,n){
        cin >>t1 >> t2 >> t3;
        a.at(i)=t1+t2+t3;
        b[i]=make_pair(a.at(i),i);
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    ll m=lower_bound(a.begin(),a.end(),a.at(k-1)-300)-a.begin();

    vector <string> c(n);
    rep(i,n){
        if(n<=m)
            c.at(b.at(i).second)="No";
        else
            c.at(b.at(i).second)="Yes";
    }
  return 0;

}
