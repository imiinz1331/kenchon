#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)
typedef pair<ll,ll> P;

int main() {
    ll n,sum=0;
    cin >> n;
    //必要な時間
    vector<ll> d(n);
    //終了時間とインデックスのペアの配列
    vector<P> t(n);
    bool ans=true;

    rep(i,n){
        //必要な時間と終了時間の入力
        cin >> d[i] >> t[i].first;
        //インデックスの入力
        t[i].second=i;
    }

    //終了時間のソート(ペアは最初の要素でソートする)
    sort(t.begin(),t.end());

    rep(i,n){
        //終了時間と次の終了時間を持つ仕事の開始時間が重なっていたら完了できない
      if(sum+d[t[i].second]>t[i].first){
            ans=false;
        }
      sum+=d[t[i].second];

    }

    cout << (ans?"Yes":"No") << endl;
    return 0;
}
