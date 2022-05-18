#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

/*
入力形式を
N W
a0 a1 ... an-1
とする
*/

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> A(N);
    rep(i,N){cin >> A.at(i);}
    vector<vector<ll>> dp(N+1,vector<ll>(W+1));
    ll ans = 0;
    rep(i,N){//行を埋める（a_iまで使うか使わないか選んだ場合の和の取り方）
        rep(j,W+1){

            //他のものを選ばなかった時 or j==0の時
            if(j == A.at(i) || j==0){dp.at(i).at(j)=1;}

            //i-1の行のものにa_iを加えた時と加えなかった時をそれぞれ埋める
            else if(i>0){
                if(dp.at(i-1).at(j)==1){dp.at(i).at(j)=1;}
                if(j-A.at(i)>=0){//i-1の行でj-a_iが作れる時、a_iを使えばいいので1にする
                    if(dp.at(i-1).at(j-A.at(i))==1){dp.at(i).at(j)=1;}
                }
            }
        }

        //1行埋めて重さがWになるものがあればans++
        if(dp.at(i).at(W)>0){ans ++;}
    }


/*確認用 N×W+1 の図が出ます*/
/*    rep(i,N){
        rep(j,W+1){
            cout << dp.at(i).at(j) << " ";
        }
        cout << endl;
    }
*/

    if(ans>0){cout << "Yes" << endl;}
    else{cout << "No" << endl;}
    return 0;
}
