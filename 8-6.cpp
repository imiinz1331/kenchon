#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int main()
{
    // dict[v] : <a[0], a[1], ..., a[n-1]> に整数Vが含まれる個数
    unordered_map<int, int> dict;
    // dict[v]にaの値を入れる
    rep(i,n){
      cin >> a;
      dict[i] = a;
    }
    // ansにdict[b[j]]の値を足し込む
    int ans = 0; 
    rep(j,n){
      cin >> b;
      ans += dict[b];
    }
    
    cout << ans << endl;
  
    return 0;
}
